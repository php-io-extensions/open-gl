<?php

declare(strict_types=1);

it('makes vertex arrays and buffers and points an attribute into one', function (): void {
    glContext();
    [$vao] = glGenVertexArrays(1);
    [$vbo] = glGenBuffers(1);
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
    glDeleteBuffers([$vbo]);
    glDeleteVertexArrays([$vao]);
});

it('maps a buffer range to an address and unmaps it', function (): void {
    glContext();
    [$buffer] = glGenBuffers(1);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, $buffer);
    glBufferData(GL_PIXEL_PACK_BUFFER, 256, null, GL_STREAM_READ);

    $address = glMapBufferRange(GL_PIXEL_PACK_BUFFER, 0, 256, GL_MAP_READ_BIT);

    expect($address)->toBeGreaterThan(0)
        ->and(glUnmapBuffer(GL_PIXEL_PACK_BUFFER))->toBeTrue();

    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
    glDeleteBuffers([$buffer]);
});

it('fences the GPU and waits on it', function (): void {
    glContext();
    $sync = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);

    expect($sync)->toBeInstanceOf(GLsync::class)
        ->and(glClientWaitSync($sync, GL_SYNC_FLUSH_COMMANDS_BIT, 1_000_000_000))->toBeIn([GL_ALREADY_SIGNALED, GL_CONDITION_SATISFIED]);

    glDeleteSync($sync);
    expect(fn () => glClientWaitSync($sync, 0, 0))->toThrow(ValueError::class, 'GLsync has been destroyed');
});

it('refuses buffer data shorter than its size', function (): void {
    glContext();
    [$buffer] = glGenBuffers(1);
    glBindBuffer(GL_ARRAY_BUFFER, $buffer);

    expect(fn () => glBufferData(GL_ARRAY_BUFFER, 16, 'abc', GL_STATIC_DRAW))->toThrow(ValueError::class, 'must hold 16 bytes, 3 given');

    glDeleteBuffers([$buffer]);
});
