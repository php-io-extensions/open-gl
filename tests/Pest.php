<?php

declare(strict_types=1);

if (! extension_loaded('opengl')) {
    throw new RuntimeException('The opengl extension is not loaded; run ./install-macos.sh or ./install-debian-trixie.sh');
}

const MAC = PHP_OS_FAMILY === 'Darwin';
const PROBE_SIGBUS = MAC ? 10 : 7;
const PROBE_SIGSEGV = 11;

/** Skips a tests/Probes test unless the loaded ext-opengl is a probe build (--enable-opengl-probes). */
function requireProbeBuild(): void
{
    if (! defined('OPENGL_PROBES')) {
        test()->markTestSkipped('ext-opengl is not a probe build (configure --enable-opengl-probes): OPENGL_PROBES is undefined');
    }
}

/**
 * Runs $code in a child of this PHP with only ext-opengl loaded. With $context, an offscreen context
 * is current first (CGL on macOS, surfaceless EGL on Linux). $siteOff names the kept site
 * OPENGL_PROBE_OFF turns off; null keeps every site. $gmalloc runs the child under libgmalloc (macOS)
 * with Zend's allocator off, so an over-read faults at the guard page after the allocation.
 *
 * @return array{signal: ?int, stdout: string}
 */
function glProbe(string $code, ?string $siteOff, bool $context = true, bool $gmalloc = false): array
{
    $current = ! $context ? '' : (MAC
        ? "CGLChoosePixelFormat([kCGLPFAOpenGLProfile, kCGLOGLPVersion_GL4_Core, kCGLPFAAccelerated, 0], \$pf, \$n);\nCGLCreateContext(\$pf, null, \$ctx);\nCGLSetCurrentContext(\$ctx);\n"
        : "\$dpy = eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, null, null);\neglInitialize(\$dpy, \$a, \$b);\neglBindAPI(EGL_OPENGL_ES_API);\n"
            ."eglChooseConfig(\$dpy, [EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_NONE], \$cfg, 1, \$n);\n\$ctx = eglCreateContext(\$dpy, \$cfg[0], null, [EGL_CONTEXT_MAJOR_VERSION, 3, EGL_NONE]);\neglMakeCurrent(\$dpy, null, null, \$ctx);\n");
    $script = "<?php\ndeclare(strict_types=1);\n".$current."try {\n".$code."\n} catch (Throwable \$t) {\n    echo 'REFUSED ', get_class(\$t), ': ', \$t->getMessage(), \"\\n\";\n}\necho \"SURVIVED\\n\";\n";
    $file = tempnam(sys_get_temp_dir(), 'opengl-probe');
    file_put_contents($file, $script);

    $env = getenv();
    unset($env['OPENGL_PROBE_OFF'], $env['DYLD_INSERT_LIBRARIES'], $env['USE_ZEND_ALLOC']);
    $env['XDEBUG_MODE'] = 'off';
    if ($siteOff !== null) {
        $env['OPENGL_PROBE_OFF'] = $siteOff;
    }
    if ($gmalloc && MAC) {
        $env['DYLD_INSERT_LIBRARIES'] = '/usr/lib/libgmalloc.dylib';
        $env['USE_ZEND_ALLOC'] = '0';
    }

    $command = [PHP_BINARY, '-n', '-d', 'memory_limit=1G', '-d', 'extension='.ini_get('extension_dir').'/opengl.so', $file];
    $process = proc_open($command, [0 => ['file', '/dev/null', 'r'], 1 => ['pipe', 'w'], 2 => ['file', '/dev/null', 'w']], $pipes, null, $env);
    $stdout = (string) stream_get_contents($pipes[1]);
    fclose($pipes[1]);
    do {
        $status = proc_get_status($process);
        if ($status['running']) {
            usleep(20_000);
        }
    } while ($status['running']);
    proc_close($process);
    @unlink($file);

    return ['signal' => $status['signaled'] ? $status['termsig'] : null, 'stdout' => $stdout];
}

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
        $display = eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, null, null);
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
    glShaderSource($shader, 2, [glslHeader(), $body], null);
    glCompileShader($shader);
    glGetShaderiv($shader, GL_COMPILE_STATUS, $ok);
    $ok === GL_TRUE || throw new RuntimeException(shaderLog($shader));

    return $shader;
}

/** The shader's info log, sized by GL_INFO_LOG_LENGTH. */
function shaderLog(int $shader): string
{
    glGetShaderiv($shader, GL_INFO_LOG_LENGTH, $size);
    glGetShaderInfoLog($shader, $size, $length, $log);

    return $log;
}

/** The program's info log, sized by GL_INFO_LOG_LENGTH. */
function programLog(int $program): string
{
    glGetProgramiv($program, GL_INFO_LOG_LENGTH, $size);
    glGetProgramInfoLog($program, $size, $length, $log);

    return $log;
}

/** glReadPixels into an ext-fb buffer of at least $length bytes: the first $length bytes GL wrote. */
function readPixels(int $x, int $y, int $width, int $height, int $format, int $type, int $length): string
{
    $target = new FbBuffer(new FbFormat(FB_LAYOUT_RGBA8888, channelOrder: FB_CHANNELS_RGBA), max(1, intdiv($length + 3, 4)), 1);
    glReadPixels($x, $y, $width, $height, $format, $type, $target->pointer());

    return substr($target->bytes(), 0, $length);
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
    $ok === GL_TRUE || throw new RuntimeException(programLog($program));

    return $program;
}
