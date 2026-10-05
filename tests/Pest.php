<?php

declare(strict_types=1);

if (! extension_loaded('opengl')) {
    throw new RuntimeException('The opengl extension is not loaded; run ./install-macos.sh or ./install-debian-trixie.sh');
}

const MAC = PHP_OS_FAMILY === 'Darwin';

/** An offscreen context made current once for the run: CGL 4.1 core on the Mac, surfaceless EGL GLES 3.1 on Linux. */
function glContext(): void
{
    static $made = false;
    if ($made) {
        return;
    }

    if (MAC) {
        $attribs = [kCGLPFAOpenGLProfile, kCGLOGLPVersion_GL4_Core, kCGLPFAAccelerated, kCGLPFAColorSize, 24, kCGLPFAAlphaSize, 8, 0];
        CGLChoosePixelFormat($attribs, $pixelFormat, $count) === kCGLNoError || throw new RuntimeException('CGLChoosePixelFormat');
        CGLCreateContext($pixelFormat, null, $context) === kCGLNoError || throw new RuntimeException('CGLCreateContext');
        CGLDestroyPixelFormat($pixelFormat);
        CGLSetCurrentContext($context);
    } else {
        $display = eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, null);
        eglInitialize($display, $major, $minor) || throw new RuntimeException('eglInitialize ' . eglGetError());
        eglBindAPI(EGL_OPENGL_ES_API);
        eglChooseConfig($display, [EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE, EGL_PBUFFER_BIT, EGL_NONE], $configs, 1, $count);
        $context = eglCreateContext($display, $configs[0], null, [EGL_CONTEXT_MAJOR_VERSION, 3, EGL_CONTEXT_MINOR_VERSION, 1, EGL_NONE]);
        eglMakeCurrent($display, null, null, $context) || throw new RuntimeException('eglMakeCurrent ' . eglGetError());
    }

    $made = true;
}

/** The program's shader header for this dialect (the spec's two headers over one body). */
function glslHeader(): string
{
    return MAC ? "#version 150 core\n" : "#version 300 es\nprecision highp float;\n";
}

const FLAT_VERTEX = <<<'GLSL'
in vec2 point;
void main() { gl_Position = vec4(point, 0.0, 1.0); }
GLSL;

const FLAT_FRAGMENT = <<<'GLSL'
uniform vec4 rgba;
out vec4 color;
void main() { color = rgba; }
GLSL;

function compiled(int $type, string $body): int
{
    $shader = glCreateShader($type);
    glShaderSource($shader, [glslHeader(), $body]);
    glCompileShader($shader);
    glGetShaderiv($shader, GL_COMPILE_STATUS, $ok);
    $ok === GL_TRUE || throw new RuntimeException(glGetShaderInfoLog($shader));

    return $shader;
}

/** The flat program: attribute 0 is the point, uniform `rgba` the colour. */
function flatProgram(): int
{
    glContext();
    $program = glCreateProgram();
    glAttachShader($program, compiled(GL_VERTEX_SHADER, FLAT_VERTEX));
    glAttachShader($program, compiled(GL_FRAGMENT_SHADER, FLAT_FRAGMENT));
    glBindAttribLocation($program, 0, 'point');
    glLinkProgram($program);
    glGetProgramiv($program, GL_LINK_STATUS, $ok);
    $ok === GL_TRUE || throw new RuntimeException(glGetProgramInfoLog($program));

    return $program;
}
