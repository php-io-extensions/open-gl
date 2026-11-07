<?php

declare(strict_types=1);

// Site opengl-list-count (outcome 1): GL reads $count elements of the C array built from the list.
// A count past an empty list hands GL NULL; GL reads it.

beforeEach(fn () => requireProbeBuild());

it('refuses a count past the list, which GL reads past (SIGSEGV) without the refusal', function (string $code): void {
    $kept = glProbe($code, null);
    $off = glProbe($code, 'opengl-list-count');

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain('must not pass the length of argument')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with([
    'glShaderSource' => ["glShaderSource(glCreateShader(GL_VERTEX_SHADER), 1, [], null);"],
    'glDeleteBuffers' => ['glDeleteBuffers(1, []);'],
    'glDeleteTextures' => ['glDeleteTextures(1, []);'],
    'glDrawBuffers' => ['glDrawBuffers(1, []);'],
    'glUniformMatrix4fv' => [<<<'PHP'
        $header = PHP_OS_FAMILY === 'Darwin' ? "#version 150 core\n" : "#version 300 es\nprecision highp float;\n";
        $p = glCreateProgram();
        foreach ([[GL_VERTEX_SHADER, "in vec2 p; void main() { gl_Position = vec4(p, 0.0, 1.0); }"], [GL_FRAGMENT_SHADER, "uniform mat4 m; out vec4 c; void main() { c = m[0]; }"]] as [$type, $body]) {
            $s = glCreateShader($type);
            glShaderSource($s, 2, [$header, $body], null);
            glCompileShader($s);
            glAttachShader($p, $s);
        }
        glLinkProgram($p);
        glUseProgram($p);
        glUniformMatrix4fv(glGetUniformLocation($p, 'm'), 1, false, []);
        PHP],
]);
