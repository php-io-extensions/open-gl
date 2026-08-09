namespace Opengl\GL;

use Opengl\GL\GlBuffer;
use Opengl\GL\GlTexture;
use Opengl\GL\GlShader;
use Opengl\GL\GlProgram;

%{
#include "opengl-compat.h"
#include <stdio.h>
#include <string.h>
}%

/**
 * OpenGL rendering entry points (static passthrough).
 *
 * Window/context creation lives in glfw/sdl3 — this class is draw-only.
 * Named OpenGL objects are returned as Zephir DTOs with an opaque `fd` (GLuint).
 * Token constants (GL_COLOR_BUFFER_BIT, …) live in a microscrap wrapper.
 */
class GL
{
    public static function glClearColor(float red, float green, float blue, float alpha) -> void
    {
        %{
            glClearColor((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha);
        }%
    }

    public static function glClear(int mask) -> void
    {
        %{
            glClear((GLbitfield) mask);
        }%
    }

    public static function glViewport(int x, int y, int width, int height) -> void
    {
        %{
            glViewport((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height);
        }%
    }

    public static function glScissor(int x, int y, int width, int height) -> void
    {
        %{
            glScissor((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height);
        }%
    }

    public static function glEnable(int cap) -> void
    {
        %{
            glEnable((GLenum) cap);
        }%
    }

    public static function glDisable(int cap) -> void
    {
        %{
            glDisable((GLenum) cap);
        }%
    }

    public static function glFlush() -> void
    {
        %{
            glFlush();
        }%
    }

    public static function glFinish() -> void
    {
        %{
            glFinish();
        }%
    }

    public static function glGetError() -> int
    {
        int result;
        %{
            result = (zend_long) glGetError();
        }%
        return result;
    }

    public static function glGetString(int name) -> string
    {
        string result;
        %{
            const GLubyte *s = glGetString((GLenum) name);
            ZVAL_STRING(&result, s ? (const char *) s : "");
        }%
        return result;
    }

    public static function glGetIntegerv(int pname) -> int
    {
        int result;
        %{
            GLint value = 0;
            glGetIntegerv((GLenum) pname, &value);
            result = (zend_long) value;
        }%
        return result;
    }

    public static function glColor4f(float red, float green, float blue, float alpha) -> void
    {
        %{
            glColor4f((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha);
        }%
    }

    public static function glBegin(int mode) -> void
    {
        %{
            glBegin((GLenum) mode);
        }%
    }

    public static function glEnd() -> void
    {
        %{
            glEnd();
        }%
    }

    public static function glVertex2f(float x, float y) -> void
    {
        %{
            glVertex2f((GLfloat) x, (GLfloat) y);
        }%
    }

    public static function glVertex3f(float x, float y, float z) -> void
    {
        %{
            glVertex3f((GLfloat) x, (GLfloat) y, (GLfloat) z);
        }%
    }

    public static function glLoadIdentity() -> void
    {
        %{
            glLoadIdentity();
        }%
    }

    public static function glMatrixMode(int mode) -> void
    {
        %{
            glMatrixMode((GLenum) mode);
        }%
    }

    public static function glOrtho(float left, float right, float bottom, float top, float zNear, float zFar) -> void
    {
        %{
            glOrtho(
                (GLdouble) left, (GLdouble) right,
                (GLdouble) bottom, (GLdouble) top,
                (GLdouble) zNear, (GLdouble) zFar
            );
        }%
    }

    /**
     * Allocate one buffer object; `fd` is the GLuint name.
     */
    public static function glGenBuffer() -> <GlBuffer>
    {
        var buffer;
        int fd;

        %{
            GLuint name = 0;
            glGenBuffers(1, &name);
            fd = (zend_long) name;
        }%

        let buffer = new GlBuffer();
        let buffer->fd = fd;
        return buffer;
    }

    public static function glBindBuffer(int target, <GlBuffer> buffer) -> void
    {
        int fd;
        let fd = buffer->fd;
        let buffer->target = target;
        %{
            glBindBuffer((GLenum) target, (GLuint) fd);
        }%
    }

    public static function glBufferData(int target, string data, int usage) -> void
    {
        %{
            glBufferData(
                (GLenum) target,
                (GLsizeiptr) Z_STRLEN(data),
                (const void *) Z_STRVAL(data),
                (GLenum) usage
            );
        }%
    }

    public static function glBufferDataObject(<GlBuffer> buffer, string data, int usage) -> void
    {
        int target;
        int fd;
        int size;

        let target = buffer->target;
        let fd = buffer->fd;
        let buffer->usage = usage;

        %{
            size = (zend_long) Z_STRLEN(data);
            glBindBuffer((GLenum) target, (GLuint) fd);
            glBufferData(
                (GLenum) target,
                (GLsizeiptr) Z_STRLEN(data),
                (const void *) Z_STRVAL(data),
                (GLenum) usage
            );
        }%
        let buffer->size = size;
    }

    public static function glDeleteBuffer(<GlBuffer> buffer) -> void
    {
        int fd;
        let fd = buffer->fd;
        %{
            GLuint name = (GLuint) fd;
            if (name != 0) {
                glDeleteBuffers(1, &name);
            }
        }%
        let buffer->fd = 0;
        let buffer->size = 0;
    }

    public static function glGenTexture() -> <GlTexture>
    {
        var texture;
        int fd;

        %{
            GLuint name = 0;
            glGenTextures(1, &name);
            fd = (zend_long) name;
        }%

        let texture = new GlTexture();
        let texture->fd = fd;
        return texture;
    }

    public static function glBindTexture(int target, <GlTexture> texture) -> void
    {
        int fd;
        let fd = texture->fd;
        let texture->target = target;
        %{
            glBindTexture((GLenum) target, (GLuint) fd);
        }%
    }

    public static function glTexParameteri(int target, int pname, int param) -> void
    {
        %{
            glTexParameteri((GLenum) target, (GLenum) pname, (GLint) param);
        }%
    }

    public static function glDeleteTexture(<GlTexture> texture) -> void
    {
        int fd;
        let fd = texture->fd;
        %{
            GLuint name = (GLuint) fd;
            if (name != 0) {
                glDeleteTextures(1, &name);
            }
        }%
        let texture->fd = 0;
    }

    public static function glCreateShader(int type) -> <GlShader>
    {
        var shader;
        int fd;

        %{
            fd = (zend_long) glCreateShader((GLenum) type);
        }%

        let shader = new GlShader();
        let shader->fd = fd;
        let shader->type = type;
        return shader;
    }

    public static function glShaderSource(<GlShader> shader, string source) -> void
    {
        int fd;
        let fd = shader->fd;
        %{
            const char *src = Z_STRVAL(source);
            GLint len = (GLint) Z_STRLEN(source);
            glShaderSource((GLuint) fd, 1, &src, &len);
        }%
    }

    public static function glCompileShader(<GlShader> shader) -> bool
    {
        int fd;
        int status;
        let fd = shader->fd;
        %{
            GLint ok = 0;
            glCompileShader((GLuint) fd);
            glGetShaderiv((GLuint) fd, GL_COMPILE_STATUS, &ok);
            status = (zend_long) ok;
        }%
        let shader->compiled = status;
        return status != 0;
    }

    public static function glGetShaderInfoLog(<GlShader> shader) -> string
    {
        int fd;
        string result;
        let fd = shader->fd;
        %{
            GLint log_len = 0;
            glGetShaderiv((GLuint) fd, GL_INFO_LOG_LENGTH, &log_len);
            if (log_len <= 1) {
                ZVAL_STRING(&result, "");
            } else {
                char *buf = (char *) emalloc((size_t) log_len);
                GLsizei written = 0;
                glGetShaderInfoLog((GLuint) fd, log_len, &written, buf);
                ZVAL_STRINGL(&result, buf, written > 0 ? written : 0);
                efree(buf);
            }
        }%
        return result;
    }

    public static function glDeleteShader(<GlShader> shader) -> void
    {
        int fd;
        let fd = shader->fd;
        %{
            if (fd != 0) {
                glDeleteShader((GLuint) fd);
            }
        }%
        let shader->fd = 0;
        let shader->compiled = 0;
    }

    public static function glCreateProgram() -> <GlProgram>
    {
        var prog;
        int fd;

        %{
            fd = (zend_long) glCreateProgram();
        }%

        let prog = new GlProgram();
        let prog->fd = fd;
        return prog;
    }

    public static function glAttachShader(<GlProgram> prog, <GlShader> sh) -> void
    {
        var pfd;
        var sfd;
        let pfd = prog->fd;
        let sfd = sh->fd;
        %{
            glAttachShader((GLuint) Z_LVAL(pfd), (GLuint) Z_LVAL(sfd));
        }%
    }

    public static function glLinkProgram(<GlProgram> prog) -> bool
    {
        var fd;
        int status;
        let fd = prog->fd;
        %{
            GLint ok = 0;
            glLinkProgram((GLuint) Z_LVAL(fd));
            glGetProgramiv((GLuint) Z_LVAL(fd), GL_LINK_STATUS, &ok);
            status = (zend_long) ok;
        }%
        let prog->linked = status;
        return status != 0;
    }

    public static function glGetProgramInfoLog(<GlProgram> prog) -> string
    {
        var fd;
        string result;
        let fd = prog->fd;
        %{
            GLint log_len = 0;
            glGetProgramiv((GLuint) Z_LVAL(fd), GL_INFO_LOG_LENGTH, &log_len);
            if (log_len <= 1) {
                ZVAL_STRING(&result, "");
            } else {
                char *buf = (char *) emalloc((size_t) log_len);
                GLsizei written = 0;
                glGetProgramInfoLog((GLuint) Z_LVAL(fd), log_len, &written, buf);
                ZVAL_STRINGL(&result, buf, written > 0 ? written : 0);
                efree(buf);
            }
        }%
        return result;
    }

    public static function glUseProgram(<GlProgram> prog) -> void
    {
        var fd;
        let fd = prog->fd;
        %{
            glUseProgram((GLuint) Z_LVAL(fd));
        }%
    }

    public static function glUseProgramNone() -> void
    {
        %{
            glUseProgram(0);
        }%
    }

    public static function glDeleteProgram(<GlProgram> prog) -> void
    {
        var fd;
        let fd = prog->fd;
        %{
            if (Z_LVAL(fd) != 0) {
                glDeleteProgram((GLuint) Z_LVAL(fd));
            }
        }%
        let prog->fd = 0;
        let prog->linked = 0;
    }

    public static function glDrawArrays(int mode, int first, int count) -> void
    {
        %{
            glDrawArrays((GLenum) mode, (GLint) first, (GLsizei) count);
        }%
    }
}
