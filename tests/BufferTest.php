<?php

declare(strict_types=1);

it('makes vertex arrays and buffers and points an attribute into one', function (): void {
    glContext();
    glGenVertexArrays(1, $arrays);
    glGenBuffers(1, $buffers);
    [$vao] = $arrays;
    [$vbo] = $buffers;
    glBindVertexArray($vao);
    glBindBuffer(GL_ARRAY_BUFFER, $vbo);
    glBufferData(GL_ARRAY_BUFFER, 24, pack('g6', -1.0, -1.0, 1.0, -1.0, -1.0, 1.0), GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, 8, pack('g2', -0.5, -0.5));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 8, 0);

    expect(glGetError())->toBe(GL_NO_ERROR)
        ->and($vao)->toBeGreaterThan(0)
        ->and($vbo)->toBeGreaterThan(0);

    glBindVertexArray(0);
    glDeleteBuffers(1, $buffers);
    glDeleteVertexArrays(1, $arrays);
});

it('writes no names for a negative count, as GL does', function (): void {
    glContext();
    glGenBuffers(-1, $buffers);

    expect($buffers)->toBe([])
        ->and(glGetError())->toBe(0x0501); // GL_INVALID_VALUE
});

it('maps a buffer range to an address and unmaps it', function (): void {
    glContext();
    glGenBuffers(1, $buffers);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, $buffers[0]);
    glBufferData(GL_PIXEL_PACK_BUFFER, 256, null, GL_STREAM_READ);

    $address = glMapBufferRange(GL_PIXEL_PACK_BUFFER, 0, 256, GL_MAP_READ_BIT);

    expect($address)->toBeGreaterThan(0)
        ->and(glUnmapBuffer(GL_PIXEL_PACK_BUFFER))->toBeTrue();

    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
    glDeleteBuffers(1, $buffers);
});

it('fences the GPU, waits on it, and passes a released fence to GL as NULL', function (): void {
    glContext();
    $sync = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);

    expect($sync)->toBeInstanceOf(GLsync::class)
        ->and(glClientWaitSync($sync, GL_SYNC_FLUSH_COMMANDS_BIT, 1_000_000_000))->toBeIn([GL_ALREADY_SIGNALED, GL_CONDITION_SATISFIED]);

    glDeleteSync($sync);
    expect($sync->pointer())->toBe(0)
        ->and(GLsync::fromPointer(0))->toBeNull()
        ->and(glClientWaitSync($sync, 0, 0))->toBe(GL_WAIT_FAILED)
        ->and(glGetError())->toBe(0x0501); // GL_INVALID_VALUE
});

it('refuses buffer data shorter than its size, and passes null and 0 as NULL', function (): void {
    glContext();
    glGenBuffers(1, $buffers);
    glBindBuffer(GL_ARRAY_BUFFER, $buffers[0]);

    expect(fn () => glBufferData(GL_ARRAY_BUFFER, 16, 'abc', GL_STATIC_DRAW))->toThrow(ValueError::class, 'must hold 16 bytes, 3 given')
        ->and(fn () => glBufferSubData(GL_ARRAY_BUFFER, 0, 16, 0))->toThrow(ValueError::class, 'must not be address 0');

    glBufferData(GL_ARRAY_BUFFER, 16, 0, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, 16, null, GL_STATIC_DRAW);
    expect(glGetError())->toBe(GL_NO_ERROR);

    glDeleteBuffers(1, $buffers);
});

it('refuses a count past the list', function (): void {
    glContext();

    expect(fn () => glDeleteBuffers(2, [1]))->toThrow(ValueError::class, 'glDeleteBuffers(): Argument #1 ($n) must not pass the length of argument #2 ($buffers)')
        ->and(fn () => glDrawBuffers(1, []))->toThrow(ValueError::class, 'Argument #1 ($n) must not pass the length of argument #2 ($bufs)');
});

it('names the framebuffer and pack buffer bindings', function (): void {
    glContext();
    glGenFramebuffers(1, $framebuffers);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, $framebuffers[0]);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, $draw);
    glGetIntegerv(GL_PIXEL_PACK_BUFFER_BINDING, $pack);

    expect($draw)->toBe($framebuffers)
        ->and($pack)->toBe([0])
        ->and(GL_READ_FRAMEBUFFER_BINDING)->toBe(0x8CAA);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDeleteFramebuffers(1, $framebuffers);
});

it('answers every int GL writes for a pname', function (): void {
    glContext();
    glGetIntegerv(0x86A2, $count); // GL_NUM_COMPRESSED_TEXTURE_FORMATS
    glGetIntegerv(0x86A3, $formats); // GL_COMPRESSED_TEXTURE_FORMATS
    glGetIntegerv(0x0C23, $mask); // GL_COLOR_WRITEMASK
    glGetIntegerv(0x0B70, $range); // GL_DEPTH_RANGE

    expect($formats)->toHaveCount($count[0])
        ->and($mask)->toBe([1, 1, 1, 1])
        ->and($range)->toHaveCount(2);
});
