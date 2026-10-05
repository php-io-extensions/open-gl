<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue GL_NO_ERROR
 */
const GL_NO_ERROR = UNKNOWN;

/**
 * @var int
 * @cvalue GL_VERSION
 */
const GL_VERSION = UNKNOWN;

/**
 * @var int
 * @cvalue GL_RENDERER
 */
const GL_RENDERER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_VENDOR
 */
const GL_VENDOR = UNKNOWN;

/**
 * @var int
 * @cvalue GL_SHADING_LANGUAGE_VERSION
 */
const GL_SHADING_LANGUAGE_VERSION = UNKNOWN;

/**
 * @var int
 * @cvalue GL_MAX_SAMPLES
 */
const GL_MAX_SAMPLES = UNKNOWN;

/**
 * @var int
 * @cvalue GL_VIEWPORT
 */
const GL_VIEWPORT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_SCISSOR_BOX
 */
const GL_SCISSOR_BOX = UNKNOWN;

/**
 * @var int
 * @cvalue GL_MAX_VIEWPORT_DIMS
 */
const GL_MAX_VIEWPORT_DIMS = UNKNOWN;

/**
 * @var int
 * @cvalue GL_MAX_TEXTURE_SIZE
 */
const GL_MAX_TEXTURE_SIZE = UNKNOWN;

function glGetError(): int {}

function glGetString(int $name): ?string {}

/** GL_VIEWPORT and GL_SCISSOR_BOX fill 4 ints, GL_MAX_VIEWPORT_DIMS fills 2, every other pname fills 1. */
function glGetIntegerv(int $pname, ?array &$data): void {}

function glFlush(): void {}

function glFinish(): void {}

/**
 * @var int
 * @cvalue GL_VERTEX_SHADER
 */
const GL_VERTEX_SHADER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FRAGMENT_SHADER
 */
const GL_FRAGMENT_SHADER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_COMPILE_STATUS
 */
const GL_COMPILE_STATUS = UNKNOWN;

/**
 * @var int
 * @cvalue GL_LINK_STATUS
 */
const GL_LINK_STATUS = UNKNOWN;

/**
 * @var int
 * @cvalue GL_INFO_LOG_LENGTH
 */
const GL_INFO_LOG_LENGTH = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TRUE
 */
const GL_TRUE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FALSE
 */
const GL_FALSE = UNKNOWN;

function glCreateShader(int $type): int {}

function glShaderSource(int $shader, array $strings): void {}

function glCompileShader(int $shader): void {}

function glGetShaderiv(int $shader, int $pname, ?int &$params): void {}

function glGetShaderInfoLog(int $shader): string {}

function glDeleteShader(int $shader): void {}

function glCreateProgram(): int {}

function glAttachShader(int $program, int $shader): void {}

function glBindAttribLocation(int $program, int $index, string $name): void {}

function glLinkProgram(int $program): void {}

function glGetProgramiv(int $program, int $pname, ?int &$params): void {}

function glGetProgramInfoLog(int $program): string {}

function glUseProgram(int $program): void {}

function glDeleteProgram(int $program): void {}

function glGetUniformLocation(int $program, string $name): int {}

function glGetAttribLocation(int $program, string $name): int {}

function glUniform1i(int $location, int $v0): void {}

function glUniform1f(int $location, float $v0): void {}

function glUniform2f(int $location, float $v0, float $v1): void {}

function glUniform4f(int $location, float $v0, float $v1, float $v2, float $v3): void {}

/** $value is one or more 4×4 matrices, column-major, 16 floats each. The count passed to GL is count($value) / 16. */
function glUniformMatrix4fv(int $location, bool $transpose, array $value): void {}

/**
 * An address other than 0 is trusted: the binding does not check that it points at a live object.
 *
 * @not-serializable
 */
final class GLsync
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @var int
 * @cvalue GL_ARRAY_BUFFER
 */
const GL_ARRAY_BUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_ELEMENT_ARRAY_BUFFER
 */
const GL_ELEMENT_ARRAY_BUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_PIXEL_PACK_BUFFER
 */
const GL_PIXEL_PACK_BUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_PIXEL_UNPACK_BUFFER
 */
const GL_PIXEL_UNPACK_BUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_STATIC_DRAW
 */
const GL_STATIC_DRAW = UNKNOWN;

/**
 * @var int
 * @cvalue GL_DYNAMIC_DRAW
 */
const GL_DYNAMIC_DRAW = UNKNOWN;

/**
 * @var int
 * @cvalue GL_STREAM_DRAW
 */
const GL_STREAM_DRAW = UNKNOWN;

/**
 * @var int
 * @cvalue GL_STREAM_READ
 */
const GL_STREAM_READ = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FLOAT
 */
const GL_FLOAT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_UNSIGNED_BYTE
 */
const GL_UNSIGNED_BYTE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_UNSIGNED_SHORT
 */
const GL_UNSIGNED_SHORT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_UNSIGNED_INT
 */
const GL_UNSIGNED_INT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_MAP_READ_BIT
 */
const GL_MAP_READ_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_MAP_WRITE_BIT
 */
const GL_MAP_WRITE_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_MAP_INVALIDATE_RANGE_BIT
 */
const GL_MAP_INVALIDATE_RANGE_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_MAP_INVALIDATE_BUFFER_BIT
 */
const GL_MAP_INVALIDATE_BUFFER_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_SYNC_GPU_COMMANDS_COMPLETE
 */
const GL_SYNC_GPU_COMMANDS_COMPLETE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_SYNC_FLUSH_COMMANDS_BIT
 */
const GL_SYNC_FLUSH_COMMANDS_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_ALREADY_SIGNALED
 */
const GL_ALREADY_SIGNALED = UNKNOWN;

/**
 * @var int
 * @cvalue GL_CONDITION_SATISFIED
 */
const GL_CONDITION_SATISFIED = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TIMEOUT_EXPIRED
 */
const GL_TIMEOUT_EXPIRED = UNKNOWN;

/**
 * @var int
 * @cvalue GL_WAIT_FAILED
 */
const GL_WAIT_FAILED = UNKNOWN;

/**
 * @var int
 * @cvalue GL_BUFFER_SIZE
 */
const GL_BUFFER_SIZE = UNKNOWN;

function glGenVertexArrays(int $n): array {}

function glBindVertexArray(int $array): void {}

function glDeleteVertexArrays(array $arrays): void {}

function glGenBuffers(int $n): array {}

function glBindBuffer(int $target, int $buffer): void {}

/** A string must hold $size bytes. An address other than 0 is trusted. Null passes NULL. */
function glBufferData(int $target, int $size, string|int|null $data, int $usage): void {}

/** A string must hold $size bytes. An address other than 0 is trusted. */
function glBufferSubData(int $target, int $offset, int $size, string|int $data): void {}

function glDeleteBuffers(array $buffers): void {}

function glEnableVertexAttribArray(int $index): void {}

function glDisableVertexAttribArray(int $index): void {}

function glVertexAttribPointer(int $index, int $size, int $type, bool $normalized, int $stride, int $pointer): void {}

/** The mapped address, or 0 when GL fails. Bytes for PHP come from glReadPixels. */
function glMapBufferRange(int $target, int $offset, int $length, int $access): int {}

function glUnmapBuffer(int $target): bool {}

function glFenceSync(int $condition, int $flags): ?GLsync {}

function glClientWaitSync(GLsync $sync, int $flags, int $timeout): int {}

function glDeleteSync(GLsync $sync): void {}

/**
 * @var int
 * @cvalue GL_TEXTURE_2D
 */
const GL_TEXTURE_2D = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TEXTURE0
 */
const GL_TEXTURE0 = UNKNOWN;

/**
 * @var int
 * @cvalue GL_RGBA
 */
const GL_RGBA = UNKNOWN;

/**
 * @var int
 * @cvalue GL_RGBA8
 */
const GL_RGBA8 = UNKNOWN;

/**
 * @var int
 * @cvalue GL_RGB
 */
const GL_RGB = UNKNOWN;

/**
 * @var int
 * @cvalue GL_RED
 */
const GL_RED = UNKNOWN;

/**
 * @var int
 * @cvalue GL_R8
 */
const GL_R8 = UNKNOWN;

/**
 * @var int
 * @cvalue GL_DEPTH24_STENCIL8
 */
const GL_DEPTH24_STENCIL8 = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TEXTURE_MIN_FILTER
 */
const GL_TEXTURE_MIN_FILTER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TEXTURE_MAG_FILTER
 */
const GL_TEXTURE_MAG_FILTER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TEXTURE_WRAP_S
 */
const GL_TEXTURE_WRAP_S = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TEXTURE_WRAP_T
 */
const GL_TEXTURE_WRAP_T = UNKNOWN;

/**
 * @var int
 * @cvalue GL_NEAREST
 */
const GL_NEAREST = UNKNOWN;

/**
 * @var int
 * @cvalue GL_LINEAR
 */
const GL_LINEAR = UNKNOWN;

/**
 * @var int
 * @cvalue GL_CLAMP_TO_EDGE
 */
const GL_CLAMP_TO_EDGE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_UNPACK_ALIGNMENT
 */
const GL_UNPACK_ALIGNMENT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_UNPACK_ROW_LENGTH
 */
const GL_UNPACK_ROW_LENGTH = UNKNOWN;

/**
 * @var int
 * @cvalue GL_PACK_ALIGNMENT
 */
const GL_PACK_ALIGNMENT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_PACK_ROW_LENGTH
 */
const GL_PACK_ROW_LENGTH = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FRAMEBUFFER
 */
const GL_FRAMEBUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_READ_FRAMEBUFFER
 */
const GL_READ_FRAMEBUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_DRAW_FRAMEBUFFER
 */
const GL_DRAW_FRAMEBUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_RENDERBUFFER
 */
const GL_RENDERBUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_COLOR_ATTACHMENT0
 */
const GL_COLOR_ATTACHMENT0 = UNKNOWN;

/**
 * @var int
 * @cvalue GL_DEPTH_STENCIL_ATTACHMENT
 */
const GL_DEPTH_STENCIL_ATTACHMENT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FRAMEBUFFER_COMPLETE
 */
const GL_FRAMEBUFFER_COMPLETE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_COLOR_BUFFER_BIT
 */
const GL_COLOR_BUFFER_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_DEPTH_BUFFER_BIT
 */
const GL_DEPTH_BUFFER_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_STENCIL_BUFFER_BIT
 */
const GL_STENCIL_BUFFER_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_PIXEL_PACK_BUFFER_BINDING
 */
const GL_PIXEL_PACK_BUFFER_BINDING = UNKNOWN;

function glGenTextures(int $n): array {}

function glBindTexture(int $target, int $texture): void {}

/** A string must hold the bytes GL reads from the unpack state. An address other than 0 is trusted. Null passes NULL. */
function glTexImage2D(int $target, int $level, int $internalformat, int $width, int $height, int $border, int $format, int $type, string|int|null $pixels): void {}

/** A string must hold the bytes GL reads from the unpack state. An address other than 0 is trusted. */
function glTexSubImage2D(int $target, int $level, int $xoffset, int $yoffset, int $width, int $height, int $format, int $type, string|int $pixels): void {}

function glTexParameteri(int $target, int $pname, int $param): void {}

function glActiveTexture(int $texture): void {}

function glDeleteTextures(array $textures): void {}

function glPixelStorei(int $pname, int $param): void {}

function glGenFramebuffers(int $n): array {}

function glBindFramebuffer(int $target, int $framebuffer): void {}

function glFramebufferTexture2D(int $target, int $attachment, int $textarget, int $texture, int $level): void {}

function glCheckFramebufferStatus(int $target): int {}

function glDeleteFramebuffers(array $framebuffers): void {}

function glGenRenderbuffers(int $n): array {}

function glBindRenderbuffer(int $target, int $renderbuffer): void {}

function glRenderbufferStorage(int $target, int $internalformat, int $width, int $height): void {}

function glRenderbufferStorageMultisample(int $target, int $samples, int $internalformat, int $width, int $height): void {}

function glFramebufferRenderbuffer(int $target, int $attachment, int $renderbuffertarget, int $renderbuffer): void {}

function glDeleteRenderbuffers(array $renderbuffers): void {}

function glBlitFramebuffer(int $srcX0, int $srcY0, int $srcX1, int $srcY1, int $dstX0, int $dstY0, int $dstX1, int $dstY1, int $mask, int $filter): void {}

function glDrawBuffers(array $bufs): void {}

function glReadBuffer(int $src): void {}

/** Null answers the packed bytes. An int is an address, or an offset into the bound pixel-pack buffer (0 is a valid offset only then). */
function glReadPixels(int $x, int $y, int $width, int $height, int $format, int $type, ?int $pixels): ?string {}

/**
 * @var int
 * @cvalue GL_BLEND
 */
const GL_BLEND = UNKNOWN;

/**
 * @var int
 * @cvalue GL_SCISSOR_TEST
 */
const GL_SCISSOR_TEST = UNKNOWN;

/**
 * @var int
 * @cvalue GL_STENCIL_TEST
 */
const GL_STENCIL_TEST = UNKNOWN;

/**
 * @var int
 * @cvalue GL_DEPTH_TEST
 */
const GL_DEPTH_TEST = UNKNOWN;

/**
 * @var int
 * @cvalue GL_CULL_FACE
 */
const GL_CULL_FACE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_SRC_ALPHA
 */
const GL_SRC_ALPHA = UNKNOWN;

/**
 * @var int
 * @cvalue GL_ONE_MINUS_SRC_ALPHA
 */
const GL_ONE_MINUS_SRC_ALPHA = UNKNOWN;

/**
 * @var int
 * @cvalue GL_ONE
 */
const GL_ONE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_ZERO
 */
const GL_ZERO = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FUNC_ADD
 */
const GL_FUNC_ADD = UNKNOWN;

/**
 * @var int
 * @cvalue GL_ALWAYS
 */
const GL_ALWAYS = UNKNOWN;

/**
 * @var int
 * @cvalue GL_NEVER
 */
const GL_NEVER = UNKNOWN;

/**
 * @var int
 * @cvalue GL_EQUAL
 */
const GL_EQUAL = UNKNOWN;

/**
 * @var int
 * @cvalue GL_NOTEQUAL
 */
const GL_NOTEQUAL = UNKNOWN;

/**
 * @var int
 * @cvalue GL_KEEP
 */
const GL_KEEP = UNKNOWN;

/**
 * @var int
 * @cvalue GL_REPLACE
 */
const GL_REPLACE = UNKNOWN;

/**
 * @var int
 * @cvalue GL_INVERT
 */
const GL_INVERT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_INCR_WRAP
 */
const GL_INCR_WRAP = UNKNOWN;

/**
 * @var int
 * @cvalue GL_DECR_WRAP
 */
const GL_DECR_WRAP = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FRONT
 */
const GL_FRONT = UNKNOWN;

/**
 * @var int
 * @cvalue GL_BACK
 */
const GL_BACK = UNKNOWN;

/**
 * @var int
 * @cvalue GL_FRONT_AND_BACK
 */
const GL_FRONT_AND_BACK = UNKNOWN;

/**
 * @var int
 * @cvalue GL_CW
 */
const GL_CW = UNKNOWN;

/**
 * @var int
 * @cvalue GL_CCW
 */
const GL_CCW = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TRIANGLES
 */
const GL_TRIANGLES = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TRIANGLE_STRIP
 */
const GL_TRIANGLE_STRIP = UNKNOWN;

/**
 * @var int
 * @cvalue GL_TRIANGLE_FAN
 */
const GL_TRIANGLE_FAN = UNKNOWN;

/**
 * @var int
 * @cvalue GL_LINES
 */
const GL_LINES = UNKNOWN;

/**
 * @var int
 * @cvalue GL_POINTS
 */
const GL_POINTS = UNKNOWN;

function glViewport(int $x, int $y, int $width, int $height): void {}

function glScissor(int $x, int $y, int $width, int $height): void {}

function glEnable(int $cap): void {}

function glDisable(int $cap): void {}

function glBlendFunc(int $sfactor, int $dfactor): void {}

function glBlendFuncSeparate(int $srcRGB, int $dstRGB, int $srcAlpha, int $dstAlpha): void {}

function glBlendEquation(int $mode): void {}

function glColorMask(bool $red, bool $green, bool $blue, bool $alpha): void {}

function glClearColor(float $red, float $green, float $blue, float $alpha): void {}

function glClearStencil(int $s): void {}

function glClear(int $mask): void {}

function glStencilFunc(int $func, int $ref, int $mask): void {}

function glStencilOp(int $sfail, int $dpfail, int $dppass): void {}

function glStencilOpSeparate(int $face, int $sfail, int $dpfail, int $dppass): void {}

function glStencilMask(int $mask): void {}

function glCullFace(int $mode): void {}

function glFrontFace(int $mode): void {}

function glDrawArrays(int $mode, int $first, int $count): void {}

function glDrawElements(int $mode, int $count, int $type, int $indices): void {}
