<?php
/**
 * proof_headless.php — one script, two boxes, no window.
 *
 * Creates a core-profile OpenGL context with no window and no display server
 * (CGL on macOS, EGL surfaceless on Linux), renders a triangle into a 64x64
 * RGBA8 texture through an FBO with a GLSL shader pair compiled from source,
 * reads the pixels back into a Bridge buffer, and byte-checks what came out.
 *
 * Everything here is GL 3.1 core, which is the Pi 5's hardware ceiling; the
 * Mac runs the same calls on a 4.1 core context. The availability contract is
 * proved at the end: a 4.1-only entry point is live on the Mac and warns on
 * the Pi, from the same .so.
 *
 * PHP_OS_FAMILY appears exactly once, in createContext() — the extension
 * itself has no platform opinions, so choosing CGL or EGL is the caller's
 * job and this is the caller.
 *
 * Constants are inline ints with a header:line citation, because constants
 * live in jovian/ogx and never in the extension.
 *
 * Exit codes: 0 = PROOF_HEADLESS_OK, 1 = failure.
 */

declare(strict_types=1);

use OpenGL\Bridge\Bridge;
use OpenGL\CGL\CGL;
use OpenGL\EGL\EGL;
use OpenGL\GL\GL10\GL10;
use OpenGL\GL\GL11\GL11;
use OpenGL\GL\GL15\GL15;
use OpenGL\GL\GL20\GL20;
use OpenGL\GL\GL30\GL30;
use OpenGL\GL\GL41\GL41;

/* ---- glcorearb.h ---------------------------------------------------- */
const GL_COLOR_BUFFER_BIT = 0x00004000;          // glcorearb.h:74
const GL_TRIANGLES = 0x0004;                     // glcorearb.h:81
const GL_NO_ERROR = 0;                           // glcorearb.h:114
const GL_TEXTURE_2D = 0x0DE1;                    // glcorearb.h:179
const GL_UNSIGNED_BYTE = 0x1401;                 // glcorearb.h:187
const GL_FLOAT = 0x1406;                         // glcorearb.h:192
const GL_RGBA = 0x1908;                          // glcorearb.h:222
const GL_RENDERER = 0x1F01;                      // glcorearb.h:231
const GL_VERSION = 0x1F02;                       // glcorearb.h:232
const GL_NEAREST = 0x2600;                       // glcorearb.h:234
const GL_TEXTURE_MAG_FILTER = 0x2800;            // glcorearb.h:240
const GL_TEXTURE_MIN_FILTER = 0x2801;            // glcorearb.h:241
const GL_RGBA8 = 0x8058;                         // glcorearb.h:375
const GL_ARRAY_BUFFER = 0x8892;                  // glcorearb.h:606
const GL_STATIC_DRAW = 0x88E4;                   // glcorearb.h:620
const GL_FRAGMENT_SHADER = 0x8B30;               // glcorearb.h:709
const GL_VERTEX_SHADER = 0x8B31;                 // glcorearb.h:710
const GL_COMPILE_STATUS = 0x8B81;                // glcorearb.h:737
const GL_LINK_STATUS = 0x8B82;                   // glcorearb.h:738
const GL_INFO_LOG_LENGTH = 0x8B84;               // glcorearb.h:740
const GL_SHADING_LANGUAGE_VERSION = 0x8B8C;      // glcorearb.h:748
const GL_FRAMEBUFFER_COMPLETE = 0x8CD5;          // glcorearb.h:1121
const GL_COLOR_ATTACHMENT0 = 0x8CE0;             // glcorearb.h:1128
const GL_FRAMEBUFFER = 0x8D40;                   // glcorearb.h:1162

/* ---- egl.h ---------------------------------------------------------- */
const EGL_NO_CONTEXT = 0;                        // egl.h:83  (EGL_CAST(EGLContext, 0))
const EGL_NO_SURFACE = 0;                        // egl.h:85  (EGL_CAST(EGLSurface, 0))
const EGL_PBUFFER_BIT = 0x0001;                  // egl.h:86
const EGL_NONE = 0x3038;                         // egl.h:80
const EGL_SURFACE_TYPE = 0x3033;                 // egl.h:95
const EGL_RENDERABLE_TYPE = 0x3040;              // egl.h:212
const EGL_DEFAULT_DISPLAY = 0;                   // egl.h:251 (EGL_CAST(EGLNativeDisplayType, 0))
const EGL_OPENGL_API = 0x30A2;                   // egl.h:256
const EGL_OPENGL_BIT = 0x0008;                   // egl.h:257
const EGL_CONTEXT_MAJOR_VERSION = 0x3098;        // egl.h:271
const EGL_CONTEXT_MINOR_VERSION = 0x30FB;        // egl.h:272
const EGL_CONTEXT_OPENGL_PROFILE_MASK = 0x30FD;  // egl.h:273
const EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT = 0x00000001; // egl.h:277
/* Mesa's surfaceless platform. Not EGL core, so it is a plain int the caller
 * supplies to a core entry point — eglGetPlatformDisplay takes any platform
 * enum the driver knows. /usr/include/EGL/eglext.h:1093 on the Pi. */
const EGL_PLATFORM_SURFACELESS_MESA = 0x31DD;

/* ---- OpenGL.framework/Headers/CGLTypes.h ---------------------------- */
const kCGLPFAAccelerated = 73;                   // CGLTypes.h:71
const kCGLPFAOpenGLProfile = 99;                 // CGLTypes.h:78
const kCGLOGLPVersion_GL3_Core = 0x3200;         // CGLTypes.h:232
const kCGLOGLPVersion_GL4_Core = 0x4100;         // CGLTypes.h:233

const FB_SIZE = 64;

$allocated = [];

function buffer(int $bytes): int
{
    global $allocated;

    $ptr = Bridge::alloc($bytes);
    if ($ptr === 0) {
        fail("Bridge::alloc({$bytes}) failed");
    }
    $allocated[] = $ptr;

    return $ptr;
}

/** An int array marshalled into a Bridge buffer as 32-bit ints. */
function intBuffer(array $values): int
{
    $bytes = '';
    foreach ($values as $v) {
        $bytes .= pack('l', $v);
    }
    $ptr = buffer(max(4, strlen($bytes)));
    Bridge::write($ptr, 0, $bytes);

    return $ptr;
}

function readInt(int $ptr, int $offset = 0): int
{
    return unpack('l', Bridge::read($ptr, $offset, 4))[1];
}

/** A pointer-sized value read back out of an out-parameter buffer. */
function readPtr(int $ptr, int $offset = 0): int
{
    return unpack('P', Bridge::read($ptr, $offset, 8))[1];
}

function fail(string $why): never
{
    fwrite(STDERR, "proof_headless: {$why}\n");
    fwrite(STDERR, "PROOF_HEADLESS_FAILED\n");
    exit(1);
}

function step(string $what): void
{
    echo "  {$what}\n";
}

/**
 * The one place this file knows which box it is on.
 *
 * @return array{api: string, detail: string}
 */
function createContext(): array
{
    if (PHP_OS_FAMILY === 'Darwin') {
        return createCglContext();
    }

    return createEglContext();
}

function createCglContext(): array
{
    // A 4.1 core profile if the renderer has one, else 3.2 core. Both satisfy
    // the GL 3.1 core surface this proof uses.
    foreach ([kCGLOGLPVersion_GL4_Core, kCGLOGLPVersion_GL3_Core] as $profile) {
        $attribs = intBuffer([
            kCGLPFAOpenGLProfile, $profile,
            kCGLPFAAccelerated,
            0, // the attribute list terminator
        ]);
        $pixOut = buffer(8);
        $nOut = buffer(4);

        $err = CGL::CGLChoosePixelFormat($attribs, $pixOut, $nOut);
        $pix = readPtr($pixOut);
        if ($err !== 0 || $pix === 0) {
            continue;
        }

        $ctxOut = buffer(8);
        $err = CGL::CGLCreateContext($pix, 0, $ctxOut);
        $ctx = readPtr($ctxOut);
        if ($err !== 0 || $ctx === 0) {
            continue;
        }
        if (CGL::CGLSetCurrentContext($ctx) !== 0) {
            continue;
        }

        return [
            'api' => 'CGL',
            'detail' => sprintf('profile 0x%04X, context 0x%X', $profile, $ctx),
        ];
    }

    fail('CGL could not create a core-profile context');
}

function createEglContext(): array
{
    $dpy = EGL::eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, 0);
    if ($dpy === 0) {
        fail('eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA) returned EGL_NO_DISPLAY');
    }

    $majOut = buffer(4);
    $minOut = buffer(4);
    if (!EGL::eglInitialize($dpy, $majOut, $minOut)) {
        fail(sprintf('eglInitialize failed (0x%X)', EGL::eglGetError()));
    }
    $eglVersion = readInt($majOut) . '.' . readInt($minOut);

    if (!EGL::eglBindAPI(EGL_OPENGL_API)) {
        fail(sprintf('eglBindAPI(EGL_OPENGL_API) failed (0x%X)', EGL::eglGetError()));
    }

    $configAttribs = intBuffer([
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
        EGL_NONE,
    ]);
    $configOut = buffer(8);
    $nOut = buffer(4);
    if (!EGL::eglChooseConfig($dpy, $configAttribs, $configOut, 1, $nOut)) {
        fail(sprintf('eglChooseConfig failed (0x%X)', EGL::eglGetError()));
    }
    if (readInt($nOut) < 1) {
        fail('eglChooseConfig matched no config');
    }
    $config = readPtr($configOut);

    $contextAttribs = intBuffer([
        EGL_CONTEXT_MAJOR_VERSION, 3,
        EGL_CONTEXT_MINOR_VERSION, 1,
        EGL_CONTEXT_OPENGL_PROFILE_MASK, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT,
        EGL_NONE,
    ]);
    $ctx = EGL::eglCreateContext($dpy, $config, EGL_NO_CONTEXT, $contextAttribs);
    if ($ctx === 0) {
        fail(sprintf('eglCreateContext failed (0x%X)', EGL::eglGetError()));
    }

    if (!EGL::eglMakeCurrent($dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, $ctx)) {
        fail(sprintf('eglMakeCurrent (surfaceless) failed (0x%X)', EGL::eglGetError()));
    }

    return [
        'api' => 'EGL',
        'detail' => sprintf('EGL %s surfaceless, context 0x%X', $eglVersion, $ctx),
    ];
}

function compileShader(int $stage, string $source, string $label): int
{
    $shader = GL20::glCreateShader($stage);
    if ($shader === 0) {
        fail("glCreateShader({$label}) returned 0");
    }

    // The array-of-strings rule (binding-rules.md D2): count stays an int and
    // the lengths pointer stays pointer bits (0 = NULL = NUL-terminated).
    GL20::glShaderSource($shader, 1, [$source], 0);
    GL20::glCompileShader($shader);

    $status = buffer(4);
    GL20::glGetShaderiv($shader, GL_COMPILE_STATUS, $status);
    if (readInt($status) === 1) {
        return $shader;
    }

    GL20::glGetShaderiv($shader, GL_INFO_LOG_LENGTH, $status);
    $len = max(1, readInt($status));
    $log = buffer($len);
    GL20::glGetShaderInfoLog($shader, $len, 0, $log);
    fail("{$label} shader did not compile:\n" . rtrim(Bridge::read($log, 0, $len), "\0"));
}

// ---------------------------------------------------------------- main

echo "proof_headless — " . PHP_OS_FAMILY . ' / ' . php_uname('m') . "\n\n";

if (!extension_loaded('opengl')) {
    fail('the opengl extension is not loaded');
}

echo "1. loader\n";
if (!Bridge::load()) {
    fail('Bridge::load() could not open an OpenGL library');
}
step('Bridge::load() ok');

echo "\n2. context (the only platform branch in this file)\n";
$context = createContext();
step("{$context['api']}: {$context['detail']}");

// Re-load so the version gate samples the context that is now current.
Bridge::load();
$version = Bridge::contextVersion();
step("Bridge::contextVersion() = {$version['major']}.{$version['minor']}");
if ($version['major'] < 3 || ($version['major'] === 3 && $version['minor'] < 1)) {
    fail("this proof needs GL 3.1 core; the context reports {$version['major']}.{$version['minor']}");
}

echo "\n3. strings\n";
$glVersion = GL10::glGetString(GL_VERSION);
$glRenderer = GL10::glGetString(GL_RENDERER);
$glsl = GL10::glGetString(GL_SHADING_LANGUAGE_VERSION);
step("GL_VERSION                  = {$glVersion}");
step("GL_RENDERER                 = {$glRenderer}");
step("GL_SHADING_LANGUAGE_VERSION = {$glsl}");

/*
 * GLSL 1.40 is what a GL 3.1 core context gives us, and it is the version
 * this pair is written against. A core profile above 3.2 does not accept
 * 1.40, so the directive follows the context's own reported GLSL version —
 * a capability branch on data GL just handed us, not a platform branch.
 */
$glslDirective = version_compare((string) $glsl, '1.50', '<') ? '#version 140' : '#version 150 core';
step("shader directive            = {$glslDirective}");

echo "\n4. GL 3.1 core render into a 64x64 RGBA8 FBO\n";

// ---- VAO (GL 3.0): a core profile has no default vertex array object.
$vaoOut = buffer(4);
GL30::glGenVertexArrays(1, $vaoOut);
$vao = readInt($vaoOut);
GL30::glBindVertexArray($vao);
step("VAO {$vao}");

// ---- VBO (GL 1.5): one triangle, big enough to cover the centre pixel.
$vertices = pack('f*', 0.0, 0.8, -0.8, -0.8, 0.8, -0.8);
$vboOut = buffer(4);
GL15::glGenBuffers(1, $vboOut);
$vbo = readInt($vboOut);
GL15::glBindBuffer(GL_ARRAY_BUFFER, $vbo);
$vertexData = buffer(strlen($vertices));
Bridge::write($vertexData, 0, $vertices);
GL15::glBufferData(GL_ARRAY_BUFFER, strlen($vertices), $vertexData, GL_STATIC_DRAW);
step("VBO {$vbo} (" . strlen($vertices) . ' bytes)');

// ---- shaders (GL 2.0), compiled from source through the array-of-strings path.
$vs = compileShader(GL_VERTEX_SHADER, <<<GLSL
{$glslDirective}
in vec2 aPos;
void main()
{
    gl_Position = vec4(aPos, 0.0, 1.0);
}
GLSL, 'vertex');

$fs = compileShader(GL_FRAGMENT_SHADER, <<<GLSL
{$glslDirective}
out vec4 fragColour;
void main()
{
    fragColour = vec4(1.0, 0.5, 0.25, 1.0);
}
GLSL, 'fragment');

$program = GL20::glCreateProgram();
GL20::glAttachShader($program, $vs);
GL20::glAttachShader($program, $fs);
// GLSL 1.40 has no layout(location = ...), so the attribute is bound by name
// before linking.
GL20::glBindAttribLocation($program, 0, 'aPos');
GL20::glLinkProgram($program);

$status = buffer(4);
GL20::glGetProgramiv($program, GL_LINK_STATUS, $status);
if (readInt($status) !== 1) {
    GL20::glGetProgramiv($program, GL_INFO_LOG_LENGTH, $status);
    $len = max(1, readInt($status));
    $log = buffer($len);
    GL20::glGetProgramInfoLog($program, $len, 0, $log);
    fail("program did not link:\n" . rtrim(Bridge::read($log, 0, $len), "\0"));
}
GL20::glUseProgram($program);
step("program {$program} linked (vs {$vs}, fs {$fs})");

GL20::glEnableVertexAttribArray(0);
GL20::glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);

// ---- colour texture (GL 1.1) + FBO (GL 3.0)
$texOut = buffer(4);
GL11::glGenTextures(1, $texOut);
$tex = readInt($texOut);
GL11::glBindTexture(GL_TEXTURE_2D, $tex);
GL10::glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, FB_SIZE, FB_SIZE, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
GL10::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
GL10::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

$fboOut = buffer(4);
GL30::glGenFramebuffers(1, $fboOut);
$fbo = readInt($fboOut);
GL30::glBindFramebuffer(GL_FRAMEBUFFER, $fbo);
GL30::glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, $tex, 0);

$fbStatus = GL30::glCheckFramebufferStatus(GL_FRAMEBUFFER);
if ($fbStatus !== GL_FRAMEBUFFER_COMPLETE) {
    fail(sprintf('framebuffer incomplete (0x%X)', $fbStatus));
}
step(sprintf('texture %d, FBO %d, status 0x%X (COMPLETE)', $tex, $fbo, $fbStatus));

// ---- draw
GL10::glViewport(0, 0, FB_SIZE, FB_SIZE);
GL10::glClearColor(0.0, 0.0, 0.0, 1.0);
GL10::glClear(GL_COLOR_BUFFER_BIT);
GL11::glDrawArrays(GL_TRIANGLES, 0, 3);
GL10::glFinish();

$err = GL10::glGetError();
if ($err !== GL_NO_ERROR) {
    fail(sprintf('glGetError() = 0x%X after the draw', $err));
}
step('drew 3 vertices, glGetError() = GL_NO_ERROR');

echo "\n5. read back and byte-check\n";
$pixels = buffer(FB_SIZE * FB_SIZE * 4);
GL10::glReadPixels(0, 0, FB_SIZE, FB_SIZE, GL_RGBA, GL_UNSIGNED_BYTE, $pixels);

$centre = Bridge::read($pixels, ((FB_SIZE / 2) * FB_SIZE + (FB_SIZE / 2)) * 4, 4);
$corner = Bridge::read($pixels, 0, 4);
if ($centre === null || $corner === null) {
    fail('Bridge::read of the pixel buffer returned null');
}
$c = array_values(unpack('C4', $centre));
$k = array_values(unpack('C4', $corner));
step(sprintf('centre RGBA = %d,%d,%d,%d', $c[0], $c[1], $c[2], $c[3]));
step(sprintf('corner RGBA = %d,%d,%d,%d', $k[0], $k[1], $k[2], $k[3]));

// The shader writes (1.0, 0.5, 0.25, 1.0); the clear is opaque black.
if ($c[0] < 240 || $c[1] < 100 || $c[1] > 155 || $c[2] < 48 || $c[2] > 80 || $c[3] !== 255) {
    fail('the centre pixel is not the shader colour');
}
if ($k[0] !== 0 || $k[1] !== 0 || $k[2] !== 0 || $k[3] !== 255) {
    fail('the corner pixel is not the clear colour');
}
step('centre is the shader colour and the corner is the clear colour');

echo "\n6. availability contract (one .so, two ceilings)\n";
$expected41 = $version['major'] > 4 || ($version['major'] === 4 && $version['minor'] >= 1);
$has41 = Bridge::isAvailable('glProgramUniform1f');
step("context is {$version['major']}.{$version['minor']}; "
    . "Bridge::isAvailable('glProgramUniform1f') = " . ($has41 ? 'true' : 'false'));
if ($has41 !== $expected41) {
    fail('the 4.1 availability answer does not match the context version');
}

if (!$has41) {
    // Prove the refusal path: a warning, a 0, and a process that lives.
    $warned = null;
    set_error_handler(static function (int $no, string $msg) use (&$warned): bool {
        $warned = $msg;

        return true;
    });
    $pipeline = GL41::glCreateShaderProgramv(GL_VERTEX_SHADER, 1, ["{$glslDirective}\nvoid main() {}"]);
    restore_error_handler();

    if ($warned === null || !str_contains($warned, 'is not available in the current context')) {
        fail('a 4.1 call on a pre-4.1 context did not raise the expected E_WARNING');
    }
    if ($pipeline !== 0) {
        fail('a refused 4.1 call returned ' . $pipeline . ' instead of 0');
    }
    step('GL41::glCreateShaderProgramv warned and returned 0, as it must below 4.1');
} else {
    $pipelineOut = buffer(4);
    GL41::glGenProgramPipelines(1, $pipelineOut);
    $pipeline = readInt($pipelineOut);
    if ($pipeline === 0) {
        fail('glGenProgramPipelines returned 0 on a 4.1 context');
    }
    step("GL41::glGenProgramPipelines gave pipeline {$pipeline} on a 4.1 context");
}

foreach ($allocated as $ptr) {
    Bridge::free($ptr);
}

echo "\nPROOF_HEADLESS_OK\n";
exit(0);
