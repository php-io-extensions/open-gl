<?php

declare(strict_types=1);

// Site opengl-bytes-length (outcome 1): GL copies the bytes its size, or its pixel tables and the
// unpack state, call for. A shorter string is read past its end.

beforeEach(fn () => requireProbeBuild());

it('refuses a string shorter than GL reads, which GL reads past (SIGSEGV) without the refusal', function (string $code): void {
    $kept = glProbe($code, null);
    $off = glProbe($code, 'opengl-bytes-length', gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain('bytes, 1 given')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with([
    'glBufferData' => ["glGenBuffers(1, \$b);\nglBindBuffer(GL_ARRAY_BUFFER, \$b[0]);\nglBufferData(GL_ARRAY_BUFFER, 256 << 20, 'x', GL_STATIC_DRAW);\nglFinish();"],
    'glBufferSubData' => ["glGenBuffers(1, \$b);\nglBindBuffer(GL_ARRAY_BUFFER, \$b[0]);\nglBufferData(GL_ARRAY_BUFFER, 256 << 20, null, GL_STATIC_DRAW);\nglBufferSubData(GL_ARRAY_BUFFER, 0, 256 << 20, 'x');\nglFinish();"],
    'glTexImage2D' => ["glGenTextures(1, \$t);\nglBindTexture(GL_TEXTURE_2D, \$t[0]);\nglTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 8192, 8192, 0, GL_RGBA, GL_UNSIGNED_BYTE, 'x');\nglFinish();"],
    'glTexSubImage2D' => ["glGenTextures(1, \$t);\nglBindTexture(GL_TEXTURE_2D, \$t[0]);\nglTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 8192, 8192, 0, GL_RGBA, GL_UNSIGNED_BYTE, null);\nglTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 8192, 8192, GL_RGBA, GL_UNSIGNED_BYTE, 'x');\nglFinish();"],
    // A pair outside the old RGBA/RGB/RED table: GL_RG bytes.
    'glTexImage2D GL_RG' => ["glGenTextures(1, \$t);\nglBindTexture(GL_TEXTURE_2D, \$t[0]);\nglTexImage2D(GL_TEXTURE_2D, 0, 0x822B, 8192, 8192, 0, 0x8227, GL_UNSIGNED_BYTE, 'x');\nglFinish();"],
]);
