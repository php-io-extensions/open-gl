<?php

/** @generate-class-entries */

/**
 * An address other than 0 is trusted: the binding does not check that it points at a live object.
 *
 * @not-serializable
 */
final class CGLPixelFormatObj
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * An address other than 0 is trusted: the binding does not check that it points at a live object.
 *
 * @not-serializable
 */
final class CGLContextObj
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @var int
 * @cvalue kCGLPFAOpenGLProfile
 */
const kCGLPFAOpenGLProfile = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLOGLPVersion_3_2_Core
 */
const kCGLOGLPVersion_3_2_Core = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLOGLPVersion_GL4_Core
 */
const kCGLOGLPVersion_GL4_Core = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLPFAColorSize
 */
const kCGLPFAColorSize = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLPFAAlphaSize
 */
const kCGLPFAAlphaSize = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLPFADepthSize
 */
const kCGLPFADepthSize = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLPFAStencilSize
 */
const kCGLPFAStencilSize = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLPFAAccelerated
 */
const kCGLPFAAccelerated = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLPFAAllowOfflineRenderers
 */
const kCGLPFAAllowOfflineRenderers = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLCPSwapInterval
 */
const kCGLCPSwapInterval = UNKNOWN;

/**
 * @var int
 * @cvalue kCGLNoError
 */
const kCGLNoError = UNKNOWN;

/** $attribs is a list of ints ending with 0. */
function CGLChoosePixelFormat(array $attribs, ?CGLPixelFormatObj &$pix, ?int &$npix): int {}

function CGLDestroyPixelFormat(CGLPixelFormatObj $pix): void {}

function CGLCreateContext(CGLPixelFormatObj $pix, ?CGLContextObj $share, ?CGLContextObj &$ctx): int {}

function CGLReleaseContext(CGLContextObj $ctx): void {}

function CGLSetCurrentContext(?CGLContextObj $ctx): int {}

function CGLGetCurrentContext(): ?CGLContextObj {}

function CGLErrorString(int $error): string {}

function CGLFlushDrawable(CGLContextObj $ctx): int {}

/** $params must hold as many ints as $pname reads. kCGLCPSwapInterval reads one. */
function CGLSetParameter(CGLContextObj $ctx, int $pname, array $params): int {}
