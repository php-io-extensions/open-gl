---
type: Trap
title: Pointer bits only
description: Every non-string pointer crosses as a raw int. That is what keeps the layer opinion-free, and it is also a loaded gun.
tags: [trap, pointers, memory-safety, marshalling]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Pointer bits only

`GL15::glBufferData($target, $size, $ptr, $usage)` hands GL whatever int
`$ptr` is. There is no type behind it, no length behind it, and no check on
it.

## Why it is like that

The alternative is worse. Marshalling `GLint *params` as a PHP array means
deciding how many elements a given `pname` produces — and that number is a
table of OpenGL semantics, function by function and enum by enum. That table
is exactly the opinion a 1:1 layer must not hold: it would be wrong for some
enum, it would go stale with every GL version, and it would make
`glGetIntegerv` a different shape from `glGetFloatv` for no reason in the
header.

So the extension holds no such table. PHP owns the bytes:

```php
$buf = Bridge::alloc(4);
GL10::glGetIntegerv(GL_MAX_TEXTURE_SIZE, $buf);
$max = unpack('l', Bridge::read($buf, 0, 4))[1];
Bridge::free($buf);
```

`pack()`/`unpack()` do the typing, and the caller — or, properly,
**jovian/ogx** above it — is where the "how many ints does this pname
return" knowledge belongs.

## What it costs

A wrong int is a segfault, not an exception. `Bridge::read`/`write` are
bounds-checked, but the moment a pointer is handed to *GL* it is out of this
extension's hands. Passing a stale pointer, a too-small buffer, or an
arbitrary integer to `glReadPixels` will take the process down, and no amount
of glue can prevent that without inventing the table above.

Mitigations that do exist:

- `Bridge::alloc` returns zeroed memory, so a buffer is never garbage on
  first read.
- `Bridge::free`, `write` and `read` refuse a pointer this extension did not
  allocate, and refuse any range outside the allocation, with `E_WARNING`.
- Buffers come from plain `malloc`. Not `emalloc`, because the size registry
  is a process global and a request-scoped block would dangle in it after
  shutdown; and not `pemalloc`, because its failure path is
  `zend_out_of_memory()` → `exit(1)`, so `Bridge::alloc(PHP_INT_MAX)` would
  have killed the process instead of returning an error. `malloc` returns
  `NULL`, which becomes an `E_WARNING` and a `0`.
- A leaked buffer is leaked for the life of the process — free what you
  allocate — but `MSHUTDOWN` sweeps whatever is left, so it is not carried
  past the module's own teardown.

## The one exception in a generated body

Array-of-strings parameters (`glShaderSource`, `glTransformFeedbackVaryings`,
`glGetUniformIndices`, `glCreateShaderProgramv`) are the one case where the
*extension itself* allocates the array GL will walk, so it is the one case
where the extension can and must check. Each of those has a `GLsizei count`
immediately before it in the header; the generated body refuses the call with
a warning when `count` exceeds the number of strings given.

That rule is derived from the header's parameter order, not from knowing what
those four functions do — and a future header that breaks the shape **stops
the generator** rather than getting a hand-written special case. See
`renderBinding()` in `scripts/gen-gl-src.php`.
