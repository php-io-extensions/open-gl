# php-io-extensions/opengl

OpenGL core **1.0 through 4.1**, bound 1:1 into PHP. Plus the two OS-native
context APIs, so you can get a context without a window: **EGL** on Linux,
**CGL** on macOS.

```php
use OpenGL\Bridge\Bridge;
use OpenGL\GL\GL10\GL10;
use OpenGL\GL\GL15\GL15;

Bridge::load();
// ... make a context current: EGL or CGL, see examples/proof_headless.php ...

echo GL10::glGetString(0x1F02), "\n";   // GL_VERSION

$buf = Bridge::alloc(4);
GL15::glGenBuffers(1, $buf);
$vbo = unpack('l', Bridge::read($buf, 0, 4))[1];
Bridge::free($buf);
```

(Every GL call needs a current context; without one they all warn and return
0, which is the same refusal a call your context is too old for gets. The
extension will not create a context behind your back — that is a decision,
and decisions are yours.)

That is the whole idea: a C tutorial reads as PHP with `GL15::` in front of
it. `glGenBuffers` is `glGenBuffers` — not `genBuffers`, not
`Buffer::generate`, not an array of ints. **581 static methods, 17 classes,
nothing renamed and nothing invented** — and the two prototypes that cannot
be bound are visible `@reserved` lines rather than absences.

## What is here

| | classes | methods |
|---|---|---:|
| `OpenGL\GL\GL10\GL10` .. `OpenGL\GL\GL41\GL41` — one per header version block | 14 | 479 |
| `OpenGL\EGL\EGL` — EGL 1.0 .. 1.5 core | 1 | 44 |
| `OpenGL\CGL\CGL` — macOS context API | 1 | 50 (+2 reserved) |
| `OpenGL\Bridge\Bridge` — the only glue | 1 | 8 |

A function lives on the class for the version it **first appeared in**.
`glClear` is `GL10::glClear` whether you are on a 3.1 context or a 4.1 one.

Blocks 4.2 .. 4.6 (178 prototypes) are a later wave. Extension blocks
(`GL_ARB_*`, `GL_NV_*`, …) are out of scope. Constants live in
**jovian/ogx**, never here.

## One `.so`, two ceilings

No GL entry point is called by name; every one is resolved at runtime
through `dlsym` / `eglGetProcAddress`. The same binary serves a Mac at GL 4.1
and a Raspberry Pi 5 at GL 3.1 — and tells you honestly which one you are on:

```php
Bridge::isAvailable('glProgramUniform1f');   // true on the Mac, false on the Pi
GL41::glProgramUniform1f(...);               // on the Pi: E_WARNING, returns 0
```

That answer is not "did the symbol resolve" — on Mesa, GL 4.6 names resolve
fine on a 3.1 context. It is "can *this context* make this call", and it has
two halves, both re-checked on every call: **there is a context current**, and
**it is at least as new as the version block the function came from**. With no
context current every GL name is refused the same way, which is the first
thing to check when something that obviously exists starts warning.

`Bridge::procAddress()` is the deliberate exception: it reports what the
*driver* has, ungated, for diagnostics. A non-zero answer from it is not
permission to call anything.

The platform's GL runtime is a **requirement**, not a fallback. On macOS
OpenGL.framework is a load-time dependency of the module; on Linux the module
loads without `libGL.so.1`/`libEGL.so.1` and then `Bridge::load()` returns
`false` and nothing works. `build-linux.sh` checks for both before building.

## Pointers

Every pointer that is not a string crosses as **raw pointer bits in an
`int`**, `0 = NULL`. `Bridge::alloc/write/read` give you the bytes;
`pack()`/`unpack()` give you the types.

```php
$buf = Bridge::alloc(4);
GL10::glGetIntegerv(0x0D33, $buf);           // GL_MAX_TEXTURE_SIZE, glcorearb.h:175
$max = unpack('l', Bridge::read($buf, 0, 4))[1];
Bridge::free($buf);
```

This is on purpose. Marshalling `GLint *params` as a PHP array would mean the
extension holding a table of how many values every `pname` returns — which is
exactly the OpenGL opinion a 1:1 layer must not hold. It lives one layer up,
in jovian/ogx. `Bridge::read`/`write` are bounds-checked; the pointer you
hand to *GL* is your own responsibility.

The one exception, because it is the one place the extension allocates what
GL walks: `const GLchar *const *` (`glShaderSource` and three friends) takes a
PHP array of strings, and the binding refuses the call if your `count` exceeds
the array.

## Proof

`examples/proof_headless.php` runs on both boxes with no window, no display
server and no seat. It creates a context, compiles a GLSL shader pair from
source, renders a triangle into a 64×64 RGBA8 texture through an FBO, reads
the pixels back into a Bridge buffer and byte-checks them.

```
                            Mac                     Pi 5
context                     CGL                     EGL 1.5 surfaceless
GL_VERSION                  4.1 Metal - 89.4        3.1 Mesa 26.2.0
GL_RENDERER                 Apple M1 Pro            V3D 7.1.7.0
GLSL                        4.10                    1.40
centre pixel                255,128,64,255          255,128,64,255
corner pixel                0,0,0,255               0,0,0,255
glProgramUniform1f          available               warns, returns 0
```

`PHP_OS_FAMILY` appears in exactly one function of that script — choosing EGL
or CGL is the caller's decision, and the extension has no opinion about it.

## Install

**macOS** (needs Zephir: `composer global require phalcon/zephir` and the
`zephir_parser` extension):

```bash
export HERD_PHP_84_INI_SCAN_DIR="$(zsh -ic 'echo $HERD_PHP_84_INI_SCAN_DIR')"
bash install-macos.sh
php examples/proof_headless.php
```

**Debian / Ubuntu:**

```bash
bash build-linux.sh
php examples/proof_headless.php
```

`ext/` ships generated, so the Linux build needs only `phpize`/`make` — but
it refuses a committed `ext/` whose `.gen-stamp` no longer matches `src/`.

From the Mac, `bash scripts/pi-verify.sh` does the whole Pi round trip:
push, build, reflect, prove.

## Layering

**ext-opengl = OpenGL + unavoidable glue. jovian/ogx = PHP projection and
constants. venusian = composition. surface = abstraction.**

No opinions live here. No window is opened here. No constant is defined here.

## Documentation

The knowledge bundle is [`.okf/`](.okf/) — start at
[`.okf/index.md`](.okf/index.md). [`AGENTS.md`](AGENTS.md) is the short form
for agents working on this package.

MIT. Project Saturn Studios, LLC.
