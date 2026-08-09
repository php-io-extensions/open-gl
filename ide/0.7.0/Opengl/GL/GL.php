<?php

namespace Opengl\GL;

use Opengl\GL\GlBuffer;
use Opengl\GL\GlTexture;
use Opengl\GL\GlShader;
use Opengl\GL\GlProgram;

/**
 * OpenGL rendering entry points (static passthrough).
 *
 * Window/context creation lives in glfw/sdl3 — this class is draw-only.
 * Named OpenGL objects are returned as Zephir DTOs with an opaque `fd` (GLuint).
 * Token constants (GL_COLOR_BUFFER_BIT, …) live in a microscrap wrapper.
 */
class GL
{


    /**
     * @param double $red
     * @param double $green
     * @param double $blue
     * @param double $alpha
     * @return void
     */
    public static function glClearColor(float $red, float $green, float $blue, float $alpha): void
    {
    }

    /**
     * @param int $mask
     * @return void
     */
    public static function glClear(int $mask): void
    {
    }

    /**
     * @param int $x
     * @param int $y
     * @param int $width
     * @param int $height
     * @return void
     */
    public static function glViewport(int $x, int $y, int $width, int $height): void
    {
    }

    /**
     * @param int $x
     * @param int $y
     * @param int $width
     * @param int $height
     * @return void
     */
    public static function glScissor(int $x, int $y, int $width, int $height): void
    {
    }

    /**
     * @param int $cap
     * @return void
     */
    public static function glEnable(int $cap): void
    {
    }

    /**
     * @param int $cap
     * @return void
     */
    public static function glDisable(int $cap): void
    {
    }

    /**
     * @return void
     */
    public static function glFlush(): void
    {
    }

    /**
     * @return void
     */
    public static function glFinish(): void
    {
    }

    /**
     * @return int
     */
    public static function glGetError(): int
    {
    }

    /**
     * @param int $name
     * @return string
     */
    public static function glGetString(int $name): string
    {
    }

    /**
     * @param int $pname
     * @return int
     */
    public static function glGetIntegerv(int $pname): int
    {
    }

    /**
     * @param double $red
     * @param double $green
     * @param double $blue
     * @param double $alpha
     * @return void
     */
    public static function glColor4f(float $red, float $green, float $blue, float $alpha): void
    {
    }

    /**
     * @param int $mode
     * @return void
     */
    public static function glBegin(int $mode): void
    {
    }

    /**
     * @return void
     */
    public static function glEnd(): void
    {
    }

    /**
     * @param double $x
     * @param double $y
     * @return void
     */
    public static function glVertex2f(float $x, float $y): void
    {
    }

    /**
     * @param double $x
     * @param double $y
     * @param double $z
     * @return void
     */
    public static function glVertex3f(float $x, float $y, float $z): void
    {
    }

    /**
     * @return void
     */
    public static function glLoadIdentity(): void
    {
    }

    /**
     * @param int $mode
     * @return void
     */
    public static function glMatrixMode(int $mode): void
    {
    }

    /**
     * @param double $left
     * @param double $right
     * @param double $bottom
     * @param double $top
     * @param double $zNear
     * @param double $zFar
     * @return void
     */
    public static function glOrtho(float $left, float $right, float $bottom, float $top, float $zNear, float $zFar): void
    {
    }

    /**
     * Allocate one buffer object; `fd` is the GLuint name.
     *
     * @return GlBuffer
     */
    public static function glGenBuffer(): GlBuffer
    {
    }

    /**
     * @param int $target
     * @param \Opengl\GL\GlBuffer $buffer
     * @return void
     */
    public static function glBindBuffer(int $target, \Opengl\GL\GlBuffer $buffer): void
    {
    }

    /**
     * @param int $target
     * @param string $data
     * @param int $usage
     * @return void
     */
    public static function glBufferData(int $target, string $data, int $usage): void
    {
    }

    /**
     * @param \Opengl\GL\GlBuffer $buffer
     * @param string $data
     * @param int $usage
     * @return void
     */
    public static function glBufferDataObject(\Opengl\GL\GlBuffer $buffer, string $data, int $usage): void
    {
    }

    /**
     * @param \Opengl\GL\GlBuffer $buffer
     * @return void
     */
    public static function glDeleteBuffer(\Opengl\GL\GlBuffer $buffer): void
    {
    }

    /**
     * @return GlTexture
     */
    public static function glGenTexture(): GlTexture
    {
    }

    /**
     * @param int $target
     * @param \Opengl\GL\GlTexture $texture
     * @return void
     */
    public static function glBindTexture(int $target, \Opengl\GL\GlTexture $texture): void
    {
    }

    /**
     * @param int $target
     * @param int $pname
     * @param int $param
     * @return void
     */
    public static function glTexParameteri(int $target, int $pname, int $param): void
    {
    }

    /**
     * @param \Opengl\GL\GlTexture $texture
     * @return void
     */
    public static function glDeleteTexture(\Opengl\GL\GlTexture $texture): void
    {
    }

    /**
     * @param int $type
     * @return GlShader
     */
    public static function glCreateShader(int $type): GlShader
    {
    }

    /**
     * @param \Opengl\GL\GlShader $shader
     * @param string $source
     * @return void
     */
    public static function glShaderSource(\Opengl\GL\GlShader $shader, string $source): void
    {
    }

    /**
     * @param \Opengl\GL\GlShader $shader
     * @return bool
     */
    public static function glCompileShader(\Opengl\GL\GlShader $shader): bool
    {
    }

    /**
     * @param \Opengl\GL\GlShader $shader
     * @return string
     */
    public static function glGetShaderInfoLog(\Opengl\GL\GlShader $shader): string
    {
    }

    /**
     * @param \Opengl\GL\GlShader $shader
     * @return void
     */
    public static function glDeleteShader(\Opengl\GL\GlShader $shader): void
    {
    }

    /**
     * @return GlProgram
     */
    public static function glCreateProgram(): GlProgram
    {
    }

    /**
     * @param \Opengl\GL\GlProgram $prog
     * @param \Opengl\GL\GlShader $sh
     * @return void
     */
    public static function glAttachShader(\Opengl\GL\GlProgram $prog, \Opengl\GL\GlShader $sh): void
    {
    }

    /**
     * @param \Opengl\GL\GlProgram $prog
     * @return bool
     */
    public static function glLinkProgram(\Opengl\GL\GlProgram $prog): bool
    {
    }

    /**
     * @param \Opengl\GL\GlProgram $prog
     * @return string
     */
    public static function glGetProgramInfoLog(\Opengl\GL\GlProgram $prog): string
    {
    }

    /**
     * @param \Opengl\GL\GlProgram $prog
     * @return void
     */
    public static function glUseProgram(\Opengl\GL\GlProgram $prog): void
    {
    }

    /**
     * @return void
     */
    public static function glUseProgramNone(): void
    {
    }

    /**
     * @param \Opengl\GL\GlProgram $prog
     * @return void
     */
    public static function glDeleteProgram(\Opengl\GL\GlProgram $prog): void
    {
    }

    /**
     * @param int $mode
     * @param int $first
     * @param int $count
     * @return void
     */
    public static function glDrawArrays(int $mode, int $first, int $count): void
    {
    }
}
