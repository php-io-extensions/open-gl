#!/bin/bash

# JetPack 6 / Ubuntu 22.04 (Jammy) installer for the opengl PHP extension.
#
# Builds from the pre-generated C source in ext/ using phpize — no Zephir required.
# Verifies the NVIDIA OpenGL/EGL/GLES runtime stack typical of JetPack 6.
# Tested target: Jetson Orin Nano (aarch64) running JetPack 6.
#
# Usage:
#   bash install-jetpack6.sh
#
# Optional env overrides:
#   PHP_BIN      — path to the php binary   (default: first php on PATH)
#   PHP_EXT_DIR  — override the install dir  (default: from php-config)

set -Eeuo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
EXTENSION_NAME="opengl"
EXT_SRC="${SCRIPT_DIR}/ext"
BUILD_SO="${EXT_SRC}/modules/${EXTENSION_NAME}.so"
LOG_FILE="${SCRIPT_DIR}/build.log"

if [ "${EUID:-$(id -u)}" -ne 0 ]; then
    SUDO="sudo"
else
    SUDO=""
fi

die() {
    echo ""
    echo "❌  $*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "Required command not found: $1"
}

header() {
    echo "============================================"
    echo "  OpenGL Extension Installer (JetPack 6)   "
    echo "============================================"
    echo ""
}

step() { echo "$*"; }
ok()   { echo "   ✓ $*"; }

show_failure_logs() {
    if [ -f "$LOG_FILE" ]; then
        echo ""
        echo "---- Last 100 lines of build.log ----"
        tail -100 "$LOG_FILE" || true
    fi
}

ensure_opengl_runtime_jetpack() {
    step "🖼️  Verifying NVIDIA OpenGL/EGL/GLES runtime stack..."

    if ! command -v ldconfig >/dev/null 2>&1; then
        die "ldconfig is required to verify JetPack OpenGL runtime libraries."
    fi

    local cache
    cache="$(ldconfig -p 2>/dev/null || true)"
    echo "$cache" | grep -q "libGL.so" || die "Missing libGL.so in linker cache; JetPack OpenGL runtime looks incomplete."
    echo "$cache" | grep -q "libEGL.so" || die "Missing libEGL.so in linker cache; JetPack EGL runtime looks incomplete."
    echo "$cache" | grep -q "libGLESv2.so" || die "Missing libGLESv2.so in linker cache; JetPack GLES runtime looks incomplete."

    if echo "$cache" | grep -qi "nvidia"; then
        ok "NVIDIA GL stack detected in linker cache"
    else
        ok "Core GL/EGL/GLES libs detected (NVIDIA tag not explicit in cache output)"
    fi
}

ensure_gl_headers() {
    step "📚 Checking OpenGL development headers..."
    if [ -f /usr/include/GL/gl.h ] || pkg-config --exists gl 2>/dev/null; then
        ok "OpenGL headers present"
        return
    fi
    step "Installing Mesa OpenGL development packages..."
    $SUDO apt-get update -q >>"$LOG_FILE" 2>&1 || die "apt-get update failed."
    $SUDO apt-get install -y --no-install-recommends \
        libgl1-mesa-dev pkg-config \
        >>"$LOG_FILE" 2>&1 || die "Failed to install libgl1-mesa-dev."
    ok "OpenGL headers installed"
}

ensure_php_dev() {
    step "🐘 Checking PHP dev headers..."

    if command -v phpize >/dev/null 2>&1; then
        ok "phpize found: $(command -v phpize)"
        return
    fi

    local ver
    ver="$(${PHP_BIN:-php} -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;' 2>/dev/null || true)"

    step "   phpize not found — installing PHP dev headers..."
    $SUDO apt-get update -q >>"$LOG_FILE" 2>&1
    local installed=0
    for pkg in "php${ver}-dev" "php-dev"; do
        if $SUDO apt-get install -y --no-install-recommends "$pkg" \
            >>"$LOG_FILE" 2>&1; then
            installed=1
            break
        fi
    done
    [ "$installed" -eq 1 ] || die "Could not install PHP dev headers."
    command -v phpize >/dev/null 2>&1 || die "phpize still not found after install."
    ok "phpize ready"
}

header
: >"$LOG_FILE"

step "🔎 Preflight checks..."
PHP_BIN="${PHP_BIN:-$(command -v php || true)}"
[ -x "$PHP_BIN" ] || die "PHP not found. Install PHP first."
ok "PHP binary: $PHP_BIN ($("$PHP_BIN" -r 'echo PHP_VERSION;'))"

require_cmd gcc
require_cmd make
ok "gcc / make present"

ensure_php_dev
ensure_opengl_runtime_jetpack
ensure_gl_headers
echo ""

PHP_VER_MM="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')"
PHP_VER_NN="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.PHP_MINOR_VERSION;')"

PHP_BIN_DIR="$(dirname "$(realpath "$PHP_BIN" 2>/dev/null || echo "$PHP_BIN")")"
PHP_CONFIG="${PHP_BIN_DIR}/php-config"
[ -x "$PHP_CONFIG" ] || PHP_CONFIG="$(command -v php-config 2>/dev/null || true)"
[ -x "$PHP_CONFIG" ] || die "php-config not found. Try: sudo apt-get install php${PHP_VER_MM}-dev"

if [ -z "${PHP_EXT_DIR:-}" ]; then
    PHP_EXT_DIR="$("$PHP_CONFIG" --extension-dir)"
fi
[ -n "$PHP_EXT_DIR" ] || die "Could not determine PHP extension dir."

PHP_PHPIZE="${PHP_BIN_DIR}/phpize"
[ -x "$PHP_PHPIZE" ] || PHP_PHPIZE="$(command -v phpize)"

CLI_SCAN_DIR="$("$PHP_BIN" --ini 2>/dev/null \
    | awk -F': ' '/Scan for additional \.ini files in:/{print $2}' || true)"

ok "PHP version    : ${PHP_VER_MM}"
ok "Extension dir  : ${PHP_EXT_DIR}"
ok "phpize         : ${PHP_PHPIZE}"
[ -n "$CLI_SCAN_DIR" ] && ok "INI scan dir   : ${CLI_SCAN_DIR}"
echo ""

step "🧹 Cleaning previous build artifacts..."
cd "$EXT_SRC"
if [ ! -f config.m4 ]; then
    die "ext/config.m4 missing — run scripts/prepare-ext.sh on a maintainer machine first."
fi
if [ -f Makefile ]; then
    make distclean >>"$LOG_FILE" 2>&1 || true
fi
"$PHP_PHPIZE" --clean >>"$LOG_FILE" 2>&1 || true
ok "ext/ cleaned"
echo ""

export CFLAGS="${CFLAGS:-} -Wno-error -Wno-error=incompatible-pointer-types -Wno-pointer-compare"
export CPPFLAGS="${CPPFLAGS:-} -Wno-error -Wno-error=incompatible-pointer-types"

step "⚙️  Running phpize..."
"$PHP_PHPIZE" >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "phpize failed."; }
ok "phpize complete"

step "⚙️  Configuring (--enable-opengl)..."
./configure --with-php-config="$PHP_CONFIG" --enable-opengl \
    >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "./configure failed."; }
ok "configure complete"
echo ""

step "🔨 Building extension ($(nproc 2>/dev/null || echo 2) cores)..."
make -j"$(nproc 2>/dev/null || echo 2)" >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "make failed. See ${LOG_FILE}."; }
[ -f "$BUILD_SO" ] || { show_failure_logs; die "Build succeeded but ${BUILD_SO} not found."; }
ok "Build complete → ${BUILD_SO}"
echo ""

step "📦 Installing binary..."
$SUDO mkdir -p "$PHP_EXT_DIR"
$SUDO cp -f "$BUILD_SO" "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
$SUDO chmod 755 "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
ok "Copied to: ${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
echo ""

step "⚙️  Enabling extension..."
declare -a CONF_DIRS=()
if [ -n "$CLI_SCAN_DIR" ] && [ "$CLI_SCAN_DIR" != "(none)" ] && [ -d "$CLI_SCAN_DIR" ]; then
    CONF_DIRS+=("$CLI_SCAN_DIR")
fi
for d in "/etc/php/${PHP_VER_MM}/cli/conf.d" "/etc/php/${PHP_VER_MM}/fpm/conf.d" "/etc/php/${PHP_VER_MM}/apache2/conf.d" "/etc/php${PHP_VER_NN}/conf.d"; do
    [ -d "$d" ] && CONF_DIRS+=("$d")
done

INI_NAME="30-${EXTENSION_NAME}.ini"
INI_CONTENT="extension=${EXTENSION_NAME}.so"
for confd in "${CONF_DIRS[@]:-}"; do
    echo "$INI_CONTENT" | $SUDO tee "${confd}/${INI_NAME}" >/dev/null
    ok "Written: ${confd}/${INI_NAME}"
done
echo ""

step "🔍 Verifying..."
if "$PHP_BIN" -m 2>/dev/null | grep -q "^${EXTENSION_NAME}$"; then
    ok "Extension loaded"
else
    die "Extension not detected. Check ${INI_NAME} and php --ini."
fi

"$PHP_BIN" --ri opengl || true
echo ""
echo "✅ Installation complete!"
echo "Demo (requires glfw): php examples/proof_menu.php"
echo ""
