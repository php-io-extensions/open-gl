<?php

declare(strict_types=1);

// Site opengl-null-address (outcome 1): with no buffer object bound to take it as an offset, GL
// reads or writes address 0 itself. glBufferData and glTexImage2D take NULL and are not refused.

beforeEach(fn () => requireProbeBuild());

const PROBE_FRAMEBUFFER = "glGenTextures(1, \$t);\nglBindTexture(GL_TEXTURE_2D, \$t[0]);\nglTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, null);\n"
    ."glGenFramebuffers(1, \$f);\nglBindFramebuffer(GL_FRAMEBUFFER, \$f[0]);\nglFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, \$t[0], 0);\n";

it('refuses address 0 where GL reads or writes it, which crashes (SIGSEGV) without the refusal', function (string $code): void {
    $kept = glProbe($code, null);
    $off = glProbe($code, 'opengl-null-address');

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain('must not be address 0')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with(function (): array {
    $cases = [
        'glTexSubImage2D' => [PROBE_FRAMEBUFFER."glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, 0);\nglFinish();"],
        'glReadPixels' => [PROBE_FRAMEBUFFER.'glReadPixels(0, 0, 64, 64, GL_RGBA, GL_UNSIGNED_BYTE, 0);'],
    ];
    // Mesa's glBufferSubData checks the pointer; Apple's reads it.
    if (MAC) {
        $cases['glBufferSubData'] = ["glGenBuffers(1, \$b);\nglBindBuffer(GL_ARRAY_BUFFER, \$b[0]);\nglBufferData(GL_ARRAY_BUFFER, 64, null, GL_STATIC_DRAW);\nglBufferSubData(GL_ARRAY_BUFFER, 0, 64, 0);\nglFinish();"];
    }

    return $cases;
});
