namespace Opengl\GL;

/**
 * OpenGL buffer object (GLuint name).
 *
 * `fd` holds the GLuint buffer name as an opaque int (0 = none).
 */
class GlBuffer
{
    /** Opaque GLuint buffer name. 0 = unallocated / deleted. */
    public fd = 0;

    /** Last bind target (e.g. GL_ARRAY_BUFFER). 0 = unset. */
    public target = 0;

    /** Byte size of the last successful bufferData upload. */
    public size = 0;

    /** Usage hint from the last bufferData call. */
    public usage = 0;
}
