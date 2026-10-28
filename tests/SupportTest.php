<?php

declare(strict_types=1);

require_once __DIR__ . '/../scripts/support.php';

$gl = <<<'XML'
<registry>
    <feature api="gl" name="GL_VERSION_1_0" number="1.0">
        <require><command name="glClear"/><command name="glBegin"/></require>
    </feature>
    <feature api="gl" name="GL_VERSION_3_2" number="3.2">
        <require><command name="glFenceSync"/></require>
        <require profile="compatibility"><command name="glCompatOnly"/></require>
        <remove profile="core"><command name="glBegin"/></remove>
    </feature>
    <feature api="gl" name="GL_VERSION_4_5" number="4.5">
        <require><command name="glPastFloor"/></require>
    </feature>
    <feature api="gles2" name="GL_ES_VERSION_2_0" number="2.0">
        <require><command name="glClear"/></require>
    </feature>
    <feature api="gles2" name="GL_ES_VERSION_3_0" number="3.0">
        <require><command name="glFenceSync"/><command name="glReadBuffer"/></require>
    </feature>
</registry>
XML;

it('counts the core profile up to the floor, removes applied, then ES commands GL does not have', function () use ($gl): void {
    $seen = [];

    expect(support_registry($gl, 'gl', '4.1', 'core', $seen))->toBe([
        'GL_VERSION_1_0' => ['glClear'],
        'GL_VERSION_3_2' => ['glFenceSync'],
    ])->and(support_registry($gl, 'gles2', '3.0', null, $seen))->toBe([
        'GL_ES_VERSION_3_0' => ['glReadBuffer'],
    ]);
});

it('orders version names by number, not text', function (): void {
    $names = ['GL_VERSION_1_10', 'GL_VERSION_1_5', 'GL_VERSION_1_0'];
    usort($names, 'support_version_order');

    expect($names)->toBe(['GL_VERSION_1_0', 'GL_VERSION_1_5', 'GL_VERSION_1_10']);
});

it('reads the CGL functions of OpenGL.framework headers from an AST dump', function (): void {
    $ast = "TranslationUnitDecl\n"
        . "|-FunctionDecl 0x1 </SDK/System/Library/Frameworks/OpenGL.framework/Headers/OpenGL.h:10:1, col:5> col:17 CGLChoosePixelFormat 'CGLError (void)' extern\n"
        . "|-FunctionDecl 0x2 <line:11:1, col:5> col:17 CGLDestroyContext 'CGLError (void)' extern\n"
        . "|-FunctionDecl 0x3 </SDK/usr/include/stdio.h:3:1, col:5> col:17 CGLNotOpenGL 'int (void)' extern\n";

    expect(support_cgl($ast))->toBe(['CGLChoosePixelFormat', 'CGLDestroyContext']);
});

it('renders one line per command and lists the bindings that match none', function (): void {
    $md = support_render(['GL_VERSION_1_0' => ['glClear', 'glFlush']], ['glClear' => true, 'wl_egl_window_create' => true], 'OpenGL 4.1 core', '2026-10-28');

    expect($md)->toContain('- [x] `glClear`')
        ->toContain('- [ ] `glFlush`')
        ->toContain('## GL_VERSION_1_0 (1 / 2)')
        ->toContain('OpenGL 4.1 core — 1 / 2 members bound (50.0%) — 2026-10-28')
        ->toContain('- `wl_egl_window_create`');
});

it('computes the badge from the counts', function (): void {
    expect(support_badge('OpenGL API', 115, 579))
        ->toBe('[![OpenGL API](https://img.shields.io/badge/OpenGL_API-19.9%25_%28115%2F579%29-blue?style=flat-square)](SUPPORT.md)');
});
