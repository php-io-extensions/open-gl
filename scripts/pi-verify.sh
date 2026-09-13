#!/bin/bash
# Push this repo to the Pi 5 build box, build it there, and run the two
# checks that only mean anything against an installed .so: the reflection
# guard and the headless proof.
#
# The Mac generates and guards; the Pi builds and runs. Fix on the Mac,
# re-push, rebuild — never edit on the Pi.
#
# Reached through Angel's `fnk` zsh alias (sshpass-wrapped ssh); credentials
# live in ~/.zshrc and are never inlined here. The repo travels as a tar over
# fnk's stdin.
#
# Prints REFLECTION_OK and PROOF_HEADLESS_OK only when the Pi does.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
REMOTE_DIR="${PI_OPENGL_DIR:-/home/angel/opengl}"
PHP_BIN="${PI_PHP_BIN:-/usr/local/php84-zts/bin/php}"

fnk_run() {
    zsh -ic "fnk $(printf '%q' "$1")"
}

# Regenerate and strip first, so the tree that crosses is clean, stamped, and
# free of the Mac's phpize leftovers (build-linux.sh refuses a stale ext/).
echo "pi-verify: prepare-ext on the Mac"
bash "${ROOT}/scripts/prepare-ext.sh" >/dev/null

echo "pi-verify: packing ${ROOT}"
tmp="$(mktemp -t opengl-verify.XXXXXX.tgz)"
trap 'rm -f "${tmp}"' EXIT

(
    cd "${ROOT}"
    # AppleDouble ._* files change the gen-stamp and crash Zephir's parser.
    COPYFILE_DISABLE=1 tar czf "${tmp}" \
        --exclude '._*' \
        --exclude '.git' \
        --exclude 'ext/.libs' \
        --exclude 'ext/modules' \
        --exclude 'ext/autom4te.cache' \
        --exclude 'ext/build' \
        .
)

echo "pi-verify: copying to ${REMOTE_DIR}"
fnk_run "mkdir -p '${REMOTE_DIR}' && rm -rf '${REMOTE_DIR:?}/'* '${REMOTE_DIR}'/.[!.]* 2>/dev/null || true"
cat "${tmp}" | fnk_run "tar xzf - -C '${REMOTE_DIR}' --exclude '._*'"

echo "pi-verify: building on the Pi"
fnk_run "cd '${REMOTE_DIR}' && PHP_BIN='${PHP_BIN}' bash build-linux.sh"

echo "pi-verify: reflecting"
out="$(fnk_run "cd '${REMOTE_DIR}' && '${PHP_BIN}' scripts/verify-reflection.php")"
printf '%s\n' "${out}"
if ! printf '%s\n' "${out}" | grep -q 'REFLECTION_OK'; then
    echo "pi-verify: remote reflection did not print REFLECTION_OK" >&2
    exit 1
fi

echo "pi-verify: headless proof"
out="$(fnk_run "cd '${REMOTE_DIR}' && '${PHP_BIN}' examples/proof_headless.php")"
printf '%s\n' "${out}"
if ! printf '%s\n' "${out}" | grep -q 'PROOF_HEADLESS_OK'; then
    echo "pi-verify: remote proof did not print PROOF_HEADLESS_OK" >&2
    exit 1
fi

echo "pi-verify: PI_VERIFY_OK"
