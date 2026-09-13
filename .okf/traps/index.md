---
okf_version: "0.2"
---

# opengl — traps

Failure modes this extension has already hit, or is structurally exposed to.
Read the one relevant to the task; these are not a tutorial.

- [runtime-resolution-not-linking.md](/traps/runtime-resolution-not-linking.md)
  — nothing is linked, everything is `dlsym`'d, and a binding that calls a
  GL name directly breaks the one-`.so`-two-boxes contract.
- [version-ceilings.md](/traps/version-ceilings.md) — 4.1 on the Mac, 3.1 on
  the Pi, 4.2 .. 4.6 deferred. Symbol resolution is not availability.
- [pointer-bits-only.md](/traps/pointer-bits-only.md) — what the pointer rule
  buys, what it costs, and where the only guard is.
- [no-window-in-ext.md](/traps/no-window-in-ext.md) — this extension never
  opens a window and never will.
