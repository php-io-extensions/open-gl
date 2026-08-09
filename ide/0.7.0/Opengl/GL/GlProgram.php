<?php

namespace Opengl\GL;

/**
 * OpenGL program object (GLuint name).
 *
 * `fd` holds the GLuint program name as an opaque int (0 = none).
 */
class GlProgram
{

    /**
     * Opaque GLuint program name. 0 = unallocated / deleted.
     */
    public $fd = 0;

    /**
     * Non-zero after a successful link.
     */
    public $linked = 0;

}
