PHP_ARG_ENABLE(opengl, whether to enable opengl, [ --enable-opengl   Enable Opengl])

if test "$PHP_OPENGL" = "yes"; then

	dnl GCC 14+ promotes long-standing warnings to errors; Zephir-generated C
	dnl trips some of them. Demote back to warnings. GL_SILENCE_DEPRECATION
	dnl quiets macOS OpenGL deprecation noise.
	CFLAGS="$CFLAGS -Wno-error=incompatible-pointer-types -Wno-error=int-conversion -Wno-error=implicit-function-declaration -Wno-error=implicit-int -DGL_SILENCE_DEPRECATION"

	AC_DEFINE(HAVE_OPENGL, 1, [Whether you have Opengl])
	opengl_sources="opengl.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c opengl/gl/gl.zep.c
	opengl/gl/glbuffer.zep.c
	opengl/gl/glprogram.zep.c
	opengl/gl/glshader.zep.c
	opengl/gl/gltexture.zep.c "
	PHP_NEW_EXTENSION(opengl, $opengl_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "opengl/gl" "src"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done

	dnl Link system OpenGL. $[] keeps a literal $ through autoconf/m4.
	case `uname -s` in
		Darwin)
			OPENGL_SHARED_LIBADD="$[]OPENGL_SHARED_LIBADD -framework OpenGL"
			;;
		*)
			PHP_EVAL_LIBLINE(-lGL, OPENGL_SHARED_LIBADD)
			;;
	esac

	PHP_SUBST(OPENGL_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([opengl], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([opengl], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_ADD_INCLUDE([$ext_srcdir/src])
	PHP_ADD_INCLUDE([$ext_builddir/src])

	PHP_INSTALL_HEADERS([ext/opengl], [php_OPENGL.h])

fi
