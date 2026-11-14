<?php

declare(strict_types=1);

/** An 8x8 RGBA8 texture attached to a new framebuffer, bound and viewported. */
function targetFramebuffer(): void
{
    glGenTextures(1, $textures);
    glBindTexture(GL_TEXTURE_2D, $textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, null);
    glGenFramebuffers(1, $framebuffers);
    glBindFramebuffer(GL_FRAMEBUFFER, $framebuffers[0]);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, $textures[0], 0);
    glViewport(0, 0, 8, 8);
}

/** A program over FLAT_VERTEX and $fragment, attribute 0 the point. */
function blockProgram(string $fragment): int
{
    $program = glCreateProgram();
    glAttachShader($program, compiled(GL_VERTEX_SHADER, FLAT_VERTEX));
    glAttachShader($program, compiled(GL_FRAGMENT_SHADER, $fragment));
    glBindAttribLocation($program, 0, 'point');
    glLinkProgram($program);
    glGetProgramiv($program, GL_LINK_STATUS, $ok);
    $ok === GL_TRUE || throw new RuntimeException(programLog($program));

    return $program;
}

/** Two triangles over the whole viewport, drawn with $program. */
function drawCover(int $program): void
{
    glGenVertexArrays(1, $arrays);
    glBindVertexArray($arrays[0]);
    glGenBuffers(1, $buffers);
    glBindBuffer(GL_ARRAY_BUFFER, $buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, 48, pack('g12', -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 8, 0);
    glUseProgram($program);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

it('feeds a uniform block from a buffer range bound at the offset alignment', function (): void {
    glContext();
    $program = blockProgram(<<<'GLSL'
        layout(std140) uniform Paint { vec4 rgba; };
        out vec4 color;
        void main() { color = rgba; }
        GLSL);

    $index = glGetUniformBlockIndex($program, 'Paint');
    expect($index)->not->toBe(GL_INVALID_INDEX)
        ->and(glGetUniformBlockIndex($program, 'Absent'))->toBe(GL_INVALID_INDEX);
    glUniformBlockBinding($program, $index, 3);

    // Red at offset 0, green one alignment step in: binding the second range must paint green.
    glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, $alignment);
    glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, $maximum);
    expect($alignment[0])->toBeGreaterThan(0)->and($maximum[0])->toBeGreaterThanOrEqual(16384);
    $step = $alignment[0];
    $bytes = str_pad(pack('g4', 1.0, 0.0, 0.0, 1.0), $step, "\0") . pack('g4', 0.0, 1.0, 0.0, 1.0);
    glGenBuffers(1, $buffers);
    glBindBuffer(GL_UNIFORM_BUFFER, $buffers[0]);
    glBufferData(GL_UNIFORM_BUFFER, strlen($bytes), $bytes, GL_STREAM_DRAW);
    glBindBufferRange(GL_UNIFORM_BUFFER, 3, $buffers[0], $step, 16);

    targetFramebuffer();
    drawCover($program);
    expect(glGetError())->toBe(GL_NO_ERROR)
        ->and(bin2hex(readPixels(4, 4, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, 4)))->toBe('00ff00ff');
});

it('reads exact words from an R32UI texture through a usampler2D', function (): void {
    glContext();
    $program = blockProgram(<<<'GLSL'
        uniform highp usampler2D words;
        out vec4 color;
        void main() {
            uint word = texelFetch(words, ivec2(int(gl_FragCoord.x), 0), 0).r;
            color = vec4(float(word & 255u), float((word >> 8) & 255u), float((word >> 16) & 255u), float(word >> 24)) / 255.0;
        }
        GLSL);

    // The target first: it binds its own texture on unit 0.
    targetFramebuffer();

    // Integer textures take NEAREST: a linear filter makes them incomplete.
    glGenTextures(1, $textures);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, $textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    $words = [0x04030201, 0xFF80407F, 0x00000000, 0xDEADBEEF, 1, 2, 3, 4];
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, 8, 1, 0, GL_RED_INTEGER, GL_UNSIGNED_INT, pack('V8', ...$words));
    glUseProgram($program);
    glUniform1i(glGetUniformLocation($program, 'words'), 0);

    drawCover($program);
    expect(glGetError())->toBe(GL_NO_ERROR);
    $row = readPixels(0, 0, 8, 1, GL_RGBA, GL_UNSIGNED_BYTE, 32);
    expect(array_values(unpack('V8', $row)))->toBe($words);
});

it('stores RG32F and RGBA32F texels as given', function (): void {
    glContext();
    foreach ([[GL_RG32F, GL_RG, 2], [GL_RGBA32F, GL_RGBA, 4]] as [$internal, $format, $channels]) {
        glGenTextures(1, $textures);
        glBindTexture(GL_TEXTURE_2D, $textures[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, $internal, 2, 1, 0, $format, GL_FLOAT, pack('g*', ...array_fill(0, 2 * $channels, 0.25)));
        glGenFramebuffers(1, $framebuffers);
        glBindFramebuffer(GL_FRAMEBUFFER, $framebuffers[0]);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, $textures[0], 0);
        expect(glCheckFramebufferStatus(GL_FRAMEBUFFER))->toBe(GL_FRAMEBUFFER_COMPLETE)
            ->and(array_values(unpack('g*', readPixels(0, 0, 2, 1, $format, GL_FLOAT, 8 * $channels))))->toBe(array_fill(0, 2 * $channels, 0.25));
    }
});
