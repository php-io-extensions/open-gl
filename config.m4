PHP_ARG_ENABLE([opengl],
  [whether to enable opengl support],
  [AS_HELP_STRING([--enable-opengl], [Enable the OpenGL / GLES bindings with CGL or EGL])],
  [no])

if test "$PHP_OPENGL" != "no"; then
  OPENGL_SOURCES="src/opengl.c src/runtime.c src/gl_state.c src/gl_program.c src/gl_buffer.c src/gl_texture.c src/gl_draw.c"
  case $host_os in
    darwin*)
      OPENGL_SOURCES="$OPENGL_SOURCES src/cgl.c"
      OPENGL_SHARED_LIBADD="-framework OpenGL"
      OPENGL_CFLAGS="-DGL_SILENCE_DEPRECATION"
      ;;
    *)
      PKG_CHECK_MODULES([OPENGL_GLES], [egl >= 1.5 glesv2 wayland-egl])
      PHP_EVAL_INCLINE([$OPENGL_GLES_CFLAGS])
      PHP_EVAL_LIBLINE([$OPENGL_GLES_LIBS], [OPENGL_SHARED_LIBADD])
      OPENGL_SOURCES="$OPENGL_SOURCES src/egl.c"
      OPENGL_CFLAGS=""
      ;;
  esac
  PHP_SUBST([OPENGL_SHARED_LIBADD])
  PHP_NEW_EXTENSION([opengl], [$OPENGL_SOURCES], [$ext_shared],, [-DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 $OPENGL_CFLAGS])
  PHP_ADD_BUILD_DIR([$ext_builddir/src])
fi
