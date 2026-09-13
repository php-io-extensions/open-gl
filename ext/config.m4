PHP_ARG_ENABLE(opengl, whether to enable opengl, [ --enable-opengl   Enable Opengl])

if test "$PHP_OPENGL" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, OPENGL_SHARED_LIBADD)
	fi

	dnl ---- PHPGL platform link flags ----
	dnl Every GL/EGL/CGL entry point is resolved at runtime by
	dnl src/phpgl-bridge.c, so nothing here is referenced at link time.
	dnl This declares which platform runtime the extension needs; on Darwin
	dnl it also becomes a real load command, on Linux --as-needed drops it.
	case $host_os in
		darwin*)
			OPENGL_SHARED_LIBADD="$OPENGL_SHARED_LIBADD -framework OpenGL"
			;;
		*)
			OPENGL_SHARED_LIBADD="$OPENGL_SHARED_LIBADD -lEGL -lGL -ldl"
			;;
	esac

	AC_DEFINE(HAVE_OPENGL, 1, [Whether you have Opengl])
	opengl_sources="opengl.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c opengl/bridge/bridge.zep.c
	opengl/cgl/cgl.zep.c
	opengl/egl/egl.zep.c
	opengl/gl/gl10/gl10.zep.c
	opengl/gl/gl11/gl11.zep.c
	opengl/gl/gl12/gl12.zep.c
	opengl/gl/gl13/gl13.zep.c
	opengl/gl/gl14/gl14.zep.c
	opengl/gl/gl15/gl15.zep.c
	opengl/gl/gl20/gl20.zep.c
	opengl/gl/gl21/gl21.zep.c
	opengl/gl/gl30/gl30.zep.c
	opengl/gl/gl31/gl31.zep.c
	opengl/gl/gl32/gl32.zep.c
	opengl/gl/gl33/gl33.zep.c
	opengl/gl/gl40/gl40.zep.c
	opengl/gl/gl41/gl41.zep.c src/phpgl-support.c
	src/phpgl-bridge.c
	src/phpgl-registry.c
	src/gl-10.c
	src/gl-11.c
	src/gl-12.c
	src/gl-13.c
	src/gl-14.c
	src/gl-15.c
	src/gl-20.c
	src/gl-21.c
	src/gl-30.c
	src/gl-31.c
	src/gl-32.c
	src/gl-33.c
	src/gl-40.c
	src/gl-41.c
	src/egl.c
	src/cgl.c"
	PHP_NEW_EXTENSION(opengl, $opengl_sources, $ext_shared,, -Wno-error=incompatible-pointer-types -Wno-deprecated-declarations)
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "opengl/bridge opengl/cgl opengl/egl opengl/gl/gl10 opengl/gl/gl11 opengl/gl/gl12 opengl/gl/gl13 opengl/gl/gl14 opengl/gl/gl15 opengl/gl/gl20 opengl/gl/gl21 opengl/gl/gl30 opengl/gl/gl31 opengl/gl/gl32 opengl/gl/gl33 opengl/gl/gl40 opengl/gl/gl41"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done
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

	PHP_INSTALL_HEADERS([ext/opengl], [php_OPENGL.h])

fi
