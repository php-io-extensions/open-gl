<?php

declare(strict_types=1);

/** An 8x8 texture-backed framebuffer, bound as both read and draw. */
function textureFramebuffer(int $width = 8, int $height = 8): array
{
    glContext();
    [$texture] = glGenTextures(1);
    glBindTexture(GL_TEXTURE_2D, $texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, $width, $height, 0, GL_RGBA, GL_UNSIGNED_BYTE, null);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    [$framebuffer] = glGenFramebuffers(1);
    glBindFramebuffer(GL_FRAMEBUFFER, $framebuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, $texture, 0);

    return [$framebuffer, $texture];
}

it('uploads into a texture and reads the framebuffer back as a string', function (): void {
    [$framebuffer, $texture] = textureFramebuffer(4, 2);
    $bytes = random_bytes(32);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 4, 2, GL_RGBA, GL_UNSIGNED_BYTE, $bytes);

    expect(glCheckFramebufferStatus(GL_FRAMEBUFFER))->toBe(GL_FRAMEBUFFER_COMPLETE)
        ->and(glReadPixels(0, 0, 4, 2, GL_RGBA, GL_UNSIGNED_BYTE, null))->toBe($bytes);

    glDeleteFramebuffers([$framebuffer]);
    glDeleteTextures([$texture]);
});

it('sizes strings by the pixel-store alignment and row length', function (): void {
    [$framebuffer, $texture] = textureFramebuffer(3, 2);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 8);
    glPixelStorei(GL_PACK_ALIGNMENT, 8);
    // 3 RGB pixels = 9 bytes a row, padded to 16: 16 + 9 = 25 bytes for two rows.
    expect(fn () => glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 3, 2, GL_RGB, GL_UNSIGNED_BYTE, str_repeat("\0", 24)))->toThrow(ValueError::class, 'must hold 25 bytes, 24 given');
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 3, 2, GL_RGB, GL_UNSIGNED_BYTE, str_repeat("\x7f", 25));
    // OpenGL ES rejects GL_RGB into a sized GL_RGBA8 texture. Desktop GL accepts it.
    // The binding already let the 25-byte string through; drop the driver error so it cannot fail a later glGetError().
    glGetError();

    // RGBA reads of 3 pixels: 12 bytes a row, padded to 16: 16 + 12 = 28.
    expect(strlen(glReadPixels(0, 0, 3, 2, GL_RGBA, GL_UNSIGNED_BYTE, null)))->toBe(28);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    glDeleteFramebuffers([$framebuffer]);
    glDeleteTextures([$texture]);
});

it('sizes strings by the pixel-store skips too', function (): void {
    [$framebuffer, $texture] = textureFramebuffer(3, 2);
    glPixelStorei(GL_UNPACK_SKIP_ROWS, 1);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 2);
    // Row 12 bytes; one row and two pixels skipped first: 12 + 8 + 12 + 12 = 44.
    expect(fn () => glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 3, 2, GL_RGBA, GL_UNSIGNED_BYTE, str_repeat("\0", 24)))->toThrow(ValueError::class, 'must hold 44 bytes, 24 given');
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 3, 2, GL_RGBA, GL_UNSIGNED_BYTE, str_repeat("\0", 20).str_repeat("\x11\x22\x33\x44", 6));
    glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);

    glPixelStorei(GL_PACK_SKIP_ROWS, 1);
    glPixelStorei(GL_PACK_SKIP_PIXELS, 2);
    $read = glReadPixels(0, 0, 3, 2, GL_RGBA, GL_UNSIGNED_BYTE, null);
    glPixelStorei(GL_PACK_SKIP_ROWS, 0);
    glPixelStorei(GL_PACK_SKIP_PIXELS, 0);

    expect(strlen($read))->toBe(44)
        ->and(substr($read, 20))->toBe(str_repeat("\x11\x22\x33\x44", 6))
        ->and(glGetError())->toBe(GL_NO_ERROR);
    glDeleteFramebuffers([$framebuffer]);
    glDeleteTextures([$texture]);
});

it('reads pixels into an address', function (): void {
    [$framebuffer, $texture] = textureFramebuffer(4, 2);
    $bytes = random_bytes(32);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 4, 2, GL_RGBA, GL_UNSIGNED_BYTE, $bytes);
    $target = new FbBuffer(new FbFormat(FB_LAYOUT_RGBA8888, channelOrder: FB_CHANNELS_RGBA), 4, 2);

    expect(glReadPixels(0, 0, 4, 2, GL_RGBA, GL_UNSIGNED_BYTE, $target->pointer()))->toBeNull()
        ->and($target->bytes())->toBe($bytes);

    glDeleteFramebuffers([$framebuffer]);
    glDeleteTextures([$texture]);
})->skip(! class_exists(FbBuffer::class), 'needs ext-fb for a native address');

it('refuses a string read while a pixel-pack buffer is bound', function (): void {
    [$framebuffer, $texture] = textureFramebuffer(4, 2);
    [$pack] = glGenBuffers(1);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, $pack);
    glBufferData(GL_PIXEL_PACK_BUFFER, 32, null, GL_STREAM_READ);

    try {
        expect(fn () => glReadPixels(0, 0, 4, 2, GL_RGBA, GL_UNSIGNED_BYTE, null))->toThrow(ValueError::class, 'pixel-pack buffer');
        glReadPixels(0, 0, 4, 2, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        expect(glGetError())->toBe(GL_NO_ERROR);
    } finally {
        glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
        glDeleteBuffers([$pack]);
        glDeleteFramebuffers([$framebuffer]);
        glDeleteTextures([$texture]);
    }
});

it('makes a complete 4x framebuffer of renderbuffers', function (): void {
    glContext();
    [$color, $stencil] = glGenRenderbuffers(2);
    [$framebuffer] = glGenFramebuffers(1);
    glBindFramebuffer(GL_FRAMEBUFFER, $framebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, $color);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_RGBA8, 8, 8);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, $color);
    glBindRenderbuffer(GL_RENDERBUFFER, $stencil);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8, 8, 8);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, $stencil);
    glDrawBuffers([GL_COLOR_ATTACHMENT0]);

    expect(glCheckFramebufferStatus(GL_FRAMEBUFFER))->toBe(GL_FRAMEBUFFER_COMPLETE);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDeleteFramebuffers([$framebuffer]);
    glDeleteRenderbuffers([$color, $stencil]);
});
