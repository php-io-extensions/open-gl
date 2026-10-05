<?php

declare(strict_types=1);

/** RGBA8 pixel at (x, y) of an 8-wide glReadPixels result: row 0 is the BOTTOM row in GL. */
function pixelAt(string $bytes, int $x, int $y): string
{
    return bin2hex(substr($bytes, ($y * 8 + $x) * 4, 4));
}

it('fills a triangle by stencil-then-cover into a 4x framebuffer, resolves with a blit, and reads it back', function (): void {
    glContext();
    $program = flatProgram();

    // The multisampled target: 4x RGBA8 + 4x depth-stencil renderbuffers.
    [$color, $stencil] = glGenRenderbuffers(2);
    [$msaa, $resolvedFramebuffer] = glGenFramebuffers(2);
    glBindFramebuffer(GL_FRAMEBUFFER, $msaa);
    glBindRenderbuffer(GL_RENDERBUFFER, $color);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_RGBA8, 8, 8);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, $color);
    glBindRenderbuffer(GL_RENDERBUFFER, $stencil);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8, 8, 8);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, $stencil);

    // The resolve target: one sample, a texture.
    [$resolved] = glGenTextures(1);
    glBindTexture(GL_TEXTURE_2D, $resolved);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, null);
    glBindFramebuffer(GL_FRAMEBUFFER, $resolvedFramebuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, $resolved, 0);

    // The triangle (-1,-1), (1,-1), (-1,1), then a cover quad as two triangles.
    [$vao] = glGenVertexArrays(1);
    [$vbo] = glGenBuffers(1);
    glBindVertexArray($vao);
    glBindBuffer(GL_ARRAY_BUFFER, $vbo);
    glBufferData(GL_ARRAY_BUFFER, 72, pack('g18', -1.0, -1.0, 1.0, -1.0, -1.0, 1.0,   -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 8, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, $msaa);
    glViewport(0, 0, 8, 8);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearStencil(0);
    glStencilMask(0xFF);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glUseProgram($program);
    glEnable(GL_STENCIL_TEST);
    // Stencil: invert where the triangle covers, no colour written.
    glColorMask(false, false, false, false);
    glStencilFunc(GL_ALWAYS, 0, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // Cover: red where the stencil is not 0, and the stencil back to 0.
    glColorMask(true, true, true, true);
    glStencilFunc(GL_NOTEQUAL, 0, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_ZERO);
    glUniform4f(glGetUniformLocation($program, 'rgba'), 1.0, 0.0, 0.0, 1.0);
    glDrawArrays(GL_TRIANGLES, 3, 6);
    glDisable(GL_STENCIL_TEST);

    // Resolve: the 4x framebuffer blitted into the texture.
    glBindFramebuffer(GL_READ_FRAMEBUFFER, $msaa);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, $resolvedFramebuffer);
    glBlitFramebuffer(0, 0, 8, 8, 0, 0, 8, 8, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, $resolvedFramebuffer);
    $pixels = glReadPixels(0, 0, 8, 8, GL_RGBA, GL_UNSIGNED_BYTE, null);

    // The same read into a pixel-pack buffer, fenced, mapped: the pipe's path.
    [$pack] = glGenBuffers(1);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, $pack);
    glBufferData(GL_PIXEL_PACK_BUFFER, 256, null, GL_STREAM_READ);
    glReadPixels(0, 0, 8, 8, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    $sync = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
    $waited = glClientWaitSync($sync, GL_SYNC_FLUSH_COMMANDS_BIT, 1_000_000_000);
    $mapped = glMapBufferRange(GL_PIXEL_PACK_BUFFER, 0, 256, GL_MAP_READ_BIT);

    expect(glGetError())->toBe(GL_NO_ERROR)
        ->and($waited)->toBeIn([GL_ALREADY_SIGNALED, GL_CONDITION_SATISFIED])
        ->and($mapped)->toBeGreaterThan(0)
        // GL rows run bottom-up: the triangle is the lower-left half.
        ->and(pixelAt($pixels, 1, 1))->toBe('ff0000ff')
        ->and(pixelAt($pixels, 1, 5))->toBe('ff0000ff')
        ->and(pixelAt($pixels, 5, 1))->toBe('ff0000ff')
        ->and(pixelAt($pixels, 6, 6))->toBe('000000ff')
        // The hypotenuse runs through pixel centres (i, 7 - i): resolved from 4 samples, neither solid colour.
        ->and(array_filter(range(0, 7), fn (int $i): bool => in_array(pixelAt($pixels, $i, 7 - $i), ['ff0000ff', '000000ff'], true)))->toBe([]);

    glUnmapBuffer(GL_PIXEL_PACK_BUFFER);
    glDeleteSync($sync);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindVertexArray(0);
    glDeleteBuffers([$vbo, $pack]);
    glDeleteVertexArrays([$vao]);
    glDeleteFramebuffers([$msaa, $resolvedFramebuffer]);
    glDeleteRenderbuffers([$color, $stencil]);
    glDeleteTextures([$resolved]);
    glDeleteProgram($program);
});

it('sets the remaining state without error', function (): void {
    glContext();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glBlendEquation(GL_FUNC_ADD);
    glEnable(GL_SCISSOR_TEST);
    glScissor(0, 0, 4, 4);
    glStencilOpSeparate(GL_FRONT, GL_KEEP, GL_KEEP, GL_INCR_WRAP);
    glStencilOpSeparate(GL_BACK, GL_KEEP, GL_KEEP, GL_DECR_WRAP);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glGetIntegerv(GL_SCISSOR_BOX, $box);

    expect($box)->toBe([0, 0, 4, 4])->and(glGetError())->toBe(GL_NO_ERROR);

    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_BLEND);
    glFinish();
});
