#ifndef PHP_IO_OPENGL_COMPAT_H
#define PHP_IO_OPENGL_COMPAT_H

/**
 * Platform OpenGL headers for php-io-extensions/open-gl.
 * System headers only for v0.5 (no glad/GLEW yet).
 */
#if defined(__APPLE__)
# include <OpenGL/gl.h>
#else
# include <GL/gl.h>
#endif

#ifndef GL_SILENCE_DEPRECATION
# define GL_SILENCE_DEPRECATION 1
#endif

#endif /* PHP_IO_OPENGL_COMPAT_H */
