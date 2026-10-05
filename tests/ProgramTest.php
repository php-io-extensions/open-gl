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

it('answers the compiler log for a shader that does not compile', function (): void {
    glContext();
    $shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource($shader, [glslHeader(), 'void main() { broken }']);
    glCompileShader($shader);
    glGetShaderiv($shader, GL_COMPILE_STATUS, $ok);
    glGetShaderiv($shader, GL_INFO_LOG_LENGTH, $length);

    expect($ok)->toBe(GL_FALSE)
        ->and($length)->toBeGreaterThan(0)
        ->and(strtolower(glGetShaderInfoLog($shader)))->toContain('error');

    glDeleteShader($shader);
});

it('refuses a matrix list that is not whole 4x4 matrices', function (): void {
    glContext();
    glUniformMatrix4fv(0, false, array_fill(0, 15, 0.0));
})->throws(ValueError::class, 'multiple of 16');
