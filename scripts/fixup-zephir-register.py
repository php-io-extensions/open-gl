#!/usr/bin/env python3
"""Fix Zephir 0.19 ZEPHIR_REGISTER_CLASS truncation for Opengl\\GL\\* classes."""

from __future__ import annotations

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXT = ROOT / "ext"

FIXES = {
    "Opengl\\G\\GL": "Opengl\\GL\\GL",
    "Opengl\\G\\GlBuffer": "Opengl\\GL\\GlBuffer",
    "Opengl\\G\\GlTexture": "Opengl\\GL\\GlTexture",
    "Opengl\\G\\GlShader": "Opengl\\GL\\GlShader",
    "Opengl\\G\\GlProgram": "Opengl\\GL\\GlProgram",
}


def fix_file(path: Path) -> int:
    text = path.read_text(encoding="utf-8")
    original = text
    for bad, good in FIXES.items():
        text = text.replace(bad, good)
    text = re.sub(
        r"\bOpengl_G_(GL|GlBuffer|GlTexture|GlShader|GlProgram)\b",
        r"Opengl_GL_\1",
        text,
    )
    if text != original:
        path.write_text(text, encoding="utf-8")
        return 1
    return 0


def main() -> None:
    if not EXT.exists():
        raise SystemExit("ext/ missing — run zephir generate first")
    changed = 0
    for path in EXT.rglob("*.c"):
        changed += fix_file(path)
    for path in EXT.rglob("*.h"):
        changed += fix_file(path)
    print(f"fixup-zephir-register: touched {changed} files")


if __name__ == "__main__":
    main()
