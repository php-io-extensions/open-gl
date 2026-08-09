<?php

namespace Opengl\GL;

/**
 * OpenGL shader object (GLuint name).
 *
 * `fd` holds the GLuint shader name as an opaque int (0 = none).
 */
class GlShader
{

    /**
     * Opaque GLuint shader name. 0 = unallocated / deleted.
     */
    public $fd = 0;

    /**
     * Shader type (GL_VERTEX_SHADER / GL_FRAGMENT_SHADER).
     */
    public $type = 0;

    /**
     * Non-zero after a successful compile.
     */
    public $compiled = 0;

}
