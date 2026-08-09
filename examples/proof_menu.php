<?php
/**
 * open-gl extension — visual proof with on-screen Quit menu
 *
 * Opens a GLFW window (peer extension) and renders with Opengl\GL\GL.
 * A simple OpenGL-drawn menu offers one option: Quit.
 *
 * Controls:
 *   Click "Quit" — exit
 *   Enter / Return — activate Quit
 *   ESC or window close — exit
 *
 * Usage:
 *   php -d extension=/absolute/path/to/ext/modules/opengl.so examples/proof_menu.php
 *
 * Requires the glfw extension (already installed via Herd/PIE, or load its .so too).
 */

declare(strict_types=1);

use Glfw\GLFW\GLFW;
use Glfw\GLFW\GLFWError;
use Glfw\GLFW\Window\GLFWWindow;
use Glfw\GLFW\Context\GLFWContext;
use Glfw\GLFW\Input\GLFWInput;
use Opengl\GL\GL;

const GLFW_KEY_ESCAPE = 256;
const GLFW_KEY_ENTER = 257;
const GLFW_KEY_KP_ENTER = 335;
const GLFW_PRESS = 1;
const GLFW_MOUSE_BUTTON_LEFT = 0;
const GLFW_CONTEXT_VERSION_MAJOR = 0x00022002;
const GLFW_CONTEXT_VERSION_MINOR = 0x00022003;
const GLFW_OPENGL_PROFILE = 0x00022008;
const GLFW_OPENGL_ANY_PROFILE = 0;
const GLFW_RESIZABLE = 0x00020003;

const GL_COLOR_BUFFER_BIT = 0x00004000;
const GL_PROJECTION = 0x1701;
const GL_MODELVIEW = 0x1700;
const GL_QUADS = 0x0007;
const GL_VENDOR = 0x1F00;
const GL_RENDERER = 0x1F01;
const GL_VERSION = 0x1F02;

function hsv_to_rgb(float $h, float $s, float $v): array
{
    $i = (int) floor($h * 6.0);
    $f = $h * 6.0 - $i;
    $p = $v * (1.0 - $s);
    $q = $v * (1.0 - $f * $s);
    $t = $v * (1.0 - (1.0 - $f) * $s);

    return match ($i % 6) {
        0 => [$v, $t, $p],
        1 => [$q, $v, $p],
        2 => [$p, $v, $t],
        3 => [$p, $q, $v],
        4 => [$t, $p, $v],
        default => [$v, $p, $q],
    };
}

/** Draw an axis-aligned quad in window/logical coordinates (origin bottom-left). */
function draw_quad(float $x0, float $y0, float $x1, float $y1, float $r, float $g, float $b): void
{
    GL::glColor4f($r, $g, $b, 1.0);
    GL::glBegin(GL_QUADS);
    GL::glVertex2f($x0, $y0);
    GL::glVertex2f($x1, $y0);
    GL::glVertex2f($x1, $y1);
    GL::glVertex2f($x0, $y1);
    GL::glEnd();
}

if (!extension_loaded('glfw')) {
    fwrite(STDERR, "glfw extension is NOT loaded (needed for the window/context).\n");
    exit(1);
}
if (!extension_loaded('opengl')) {
    fwrite(STDERR, "opengl extension is NOT loaded.\n");
    exit(1);
}

if (!GLFW::glfwInit()) {
    $err = GLFWError::glfwGetError();
    fwrite(STDERR, "glfwInit failed: {$err['description']}\n");
    exit(1);
}

GLFWWindow::glfwDefaultWindowHints();
GLFWWindow::glfwWindowHint(GLFW_RESIZABLE, 1);
GLFWWindow::glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
GLFWWindow::glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
GLFWWindow::glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

try {
    $window = GLFWWindow::glfwCreateWindow(960, 540, 'open-gl demo — Quit menu');
} catch (Throwable $e) {
    fwrite(STDERR, $e->getMessage() . "\n");
    GLFW::glfwTerminate();
    exit(1);
}

GLFWContext::glfwMakeContextCurrent($window);
GLFWContext::glfwSwapInterval(1);

$vendor = GL::glGetString(GL_VENDOR);
$renderer = GL::glGetString(GL_RENDERER);
$version = GL::glGetString(GL_VERSION);
echo "OpenGL vendor   : {$vendor}\n";
echo "OpenGL renderer : {$renderer}\n";
echo "OpenGL version  : {$version}\n";
echo "Menu: click Quit, or press Enter / ESC.\n";

$winW = 960;
$winH = 540;
$fbW = 960;
$fbH = 540;

$syncSize = static function (int $win) use (&$winW, &$winH, &$fbW, &$fbH): void {
    $ws = GLFWWindow::glfwGetWindowSize($win);
    $fb = GLFWWindow::glfwGetFramebufferSize($win);
    $winW = max(1, (int) $ws['width']);
    $winH = max(1, (int) $ws['height']);
    $fbW = max(1, (int) $fb['width']);
    $fbH = max(1, (int) $fb['height']);
    GLFWContext::glfwMakeContextCurrent($win);
    GL::glViewport(0, 0, $fbW, $fbH);
};
$syncSize($window);

GLFWWindow::glfwSetFramebufferSizeCallback($window, function (int $win, int $w, int $h) use ($syncSize): void {
    $syncSize($win);
});

$quit = false;
GLFWInput::glfwSetKeyCallback($window, function (int $win, int $key, int $scancode, int $action, int $mods) use (&$quit): void {
    if ($action !== GLFW_PRESS) {
        return;
    }
    if ($key === GLFW_KEY_ESCAPE || $key === GLFW_KEY_ENTER || $key === GLFW_KEY_KP_ENTER) {
        $quit = true;
        GLFWWindow::glfwSetWindowShouldClose($win, 1);
    }
});

$autoQuit = getenv('OPENGL_PROOF_SECONDS');
$t0 = GLFWInput::glfwGetTime();
$autoQuitAt = ($autoQuit !== false && $autoQuit !== '')
    ? $t0 + (float) $autoQuit
    : null;

$prevClick = false;

while (!GLFWWindow::glfwWindowShouldClose($window) && !$quit) {
    $now = GLFWInput::glfwGetTime();
    if (!is_null($autoQuitAt) && $now >= $autoQuitAt) {
        break;
    }

    // Menu geometry in logical window coords (origin bottom-left for glOrtho).
    $menuX0 = 40.0;
    $menuY0 = (float) $winH - 120.0;
    $menuX1 = 280.0;
    $menuY1 = (float) $winH - 40.0;
    $itemPad = 12.0;
    $itemX0 = $menuX0 + $itemPad;
    $itemY0 = $menuY0 + $itemPad;
    $itemX1 = $menuX1 - $itemPad;
    $itemY1 = $menuY1 - $itemPad;

    $cursor = GLFWInput::glfwGetCursorPos($window);
    // GLFW cursor Y is top-left origin; convert to bottom-left.
    $cx = (float) ($cursor['xpos'] ?? $cursor['x'] ?? $cursor[0] ?? 0);
    $cyTop = (float) ($cursor['ypos'] ?? $cursor['y'] ?? $cursor[1] ?? 0);
    $cy = (float) $winH - $cyTop;
    $hover = ($cx >= $itemX0 && $cx <= $itemX1 && $cy >= $itemY0 && $cy <= $itemY1);

    $click = GLFWInput::glfwGetMouseButton($window, GLFW_MOUSE_BUTTON_LEFT) === GLFW_PRESS;
    if ($hover && $click && !$prevClick) {
        $quit = true;
        GLFWWindow::glfwSetWindowShouldClose($window, 1);
    }
    $prevClick = $click;

    $hue = fmod($now * 0.12, 1.0);
    [$br, $bg, $bb] = hsv_to_rgb($hue, 0.45, 0.28);
    GL::glClearColor($br, $bg, $bb, 1.0);
    GL::glClear(GL_COLOR_BUFFER_BIT);

    GL::glMatrixMode(GL_PROJECTION);
    GL::glLoadIdentity();
    GL::glOrtho(0.0, (float) $winW, 0.0, (float) $winH, -1.0, 1.0);
    GL::glMatrixMode(GL_MODELVIEW);
    GL::glLoadIdentity();

    // Accent triangle (something rendered beyond the menu)
    [$tr, $tg, $tb] = hsv_to_rgb(fmod($hue + 0.35, 1.0), 0.85, 0.95);
    GL::glColor4f($tr, $tg, $tb, 1.0);
    GL::glBegin(GL_QUADS);
    $cxScreen = $winW * 0.62;
    $cyScreen = $winH * 0.42;
    $s = 90.0 + 20.0 * sin($now * 2.0);
    GL::glVertex2f($cxScreen - $s, $cyScreen - $s);
    GL::glVertex2f($cxScreen + $s, $cyScreen - $s);
    GL::glVertex2f($cxScreen + $s, $cyScreen + $s);
    GL::glVertex2f($cxScreen - $s, $cyScreen + $s);
    GL::glEnd();

    // Menu panel
    draw_quad($menuX0, $menuY0, $menuX1, $menuY1, 0.08, 0.09, 0.12);
    if ($hover) {
        draw_quad($itemX0, $itemY0, $itemX1, $itemY1, 0.75, 0.25, 0.22);
    } else {
        draw_quad($itemX0, $itemY0, $itemX1, $itemY1, 0.35, 0.38, 0.45);
    }
    // Inner bar stands in for the "Quit" label (no text rasterizer in this slice).
    draw_quad($itemX0 + 24, ($itemY0 + $itemY1) * 0.5 - 4, $itemX1 - 24, ($itemY0 + $itemY1) * 0.5 + 4, 0.95, 0.95, 0.97);

    GLFWContext::glfwSwapBuffers($window);
    GLFWWindow::glfwPollEvents();
}

GLFWWindow::glfwDestroyWindow($window);
GLFW::glfwTerminate();
echo "Quit selected — window closed cleanly.\n";
exit(0);
