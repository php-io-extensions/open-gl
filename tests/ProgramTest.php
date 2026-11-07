<?php

declare(strict_types=1);

it('compiles and links the flat program in this dialect', function (): void {
    $program = flatProgram();

    expect(glGetAttribLocation($program, 'point'))->toBe(0)
        ->and(glGetUniformLocation($program, 'rgba'))->toBeGreaterThanOrEqual(0)
        ->and(glGetUniformLocation($program, 'missing'))->toBe(-1)
        ->and(glGetError())->toBe(GL_NO_ERROR);

    glUseProgram($program);
    glUniform4f(glGetUniformLocation($program, 'rgba'), 1.0, 0.0, 0.0, 1.0);
    expect(glGetError())->toBe(GL_NO_ERROR);

    glUseProgram(0);
    glDeleteProgram($program);
});

it('answers the compiler log for a shader that does not compile, up to $bufSize', function (): void {
    glContext();
    $shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource($shader, 2, [glslHeader(), 'void main() { broken }'], null);
    glCompileShader($shader);
    glGetShaderiv($shader, GL_COMPILE_STATUS, $ok);
    glGetShaderiv($shader, GL_INFO_LOG_LENGTH, $size);
    glGetShaderInfoLog($shader, $size, $length, $log);
    glGetShaderInfoLog($shader, 6, $shortLength, $short);

    expect($ok)->toBe(GL_FALSE)
        ->and($length)->toBe($size - 1)
        ->and(strlen($log))->toBe($length)
        ->and(strtolower($log))->toContain('error')
        ->and($shortLength)->toBe(5)
        ->and($short)->toBe(substr($log, 0, 5));

    glDeleteShader($shader);
});

it('reads $count strings, with or without their lengths', function (): void {
    glContext();
    $shader = glCreateShader(GL_VERTEX_SHADER);
    $body = "in vec2 point;\nvoid main() { gl_Position = vec4(point, 0.0, 1.0); }\nIGNORED";
    glShaderSource($shader, 2, [glslHeader(), $body], [-1, strlen($body) - 7]);
    glCompileShader($shader);
    glGetShaderiv($shader, GL_COMPILE_STATUS, $ok);

    expect($ok)->toBe(GL_TRUE)
        ->and(fn () => glShaderSource($shader, 3, ['a', 'b'], null))->toThrow(ValueError::class, 'Argument #2 ($count) must not pass the length of argument #3 ($string)')
        ->and(fn () => glShaderSource($shader, 2, ['a', 'b'], [1]))->toThrow(ValueError::class, 'Argument #2 ($count) must not pass the length of argument #4 ($length)');

    glDeleteShader($shader);
});

it('refuses a matrix count past the list, 16 floats a matrix', function (): void {
    glContext();
    glUniformMatrix4fv(0, 1, false, array_fill(0, 15, 0.0));
})->throws(ValueError::class, 'Argument #2 ($count) must not pass the length of argument #4 ($value)');
