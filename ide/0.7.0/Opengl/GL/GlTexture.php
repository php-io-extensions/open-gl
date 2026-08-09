<?php

namespace Opengl\GL;

/**
 * OpenGL texture object (GLuint name).
 *
 * `fd` holds the GLuint texture name as an opaque int (0 = none).
 */
class GlTexture
{

    /**
     * Opaque GLuint texture name. 0 = unallocated / deleted.
     */
    public $fd = 0;

    /**
     * Last bind target (e.g. GL_TEXTURE_2D). 0 = unset.
     */
    public $target = 0;

    /**
     * Width in texels (0 until set by caller after upload).
     */
    public $width = 0;

    /**
     * Height in texels (0 until set by caller after upload).
     */
    public $height = 0;

    /**
     * Internal / base format hint stored by caller (e.g. GL_RGBA).
     */
    public $format = 0;

}
