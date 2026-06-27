#ifndef _WIN32
#error "win32.cpp compilation error"
#endif

#include <windows.h>
#include "../Platform.h"

static LRESULT CALLBACK wnd_proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    UWXX* win = (UWXX*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

    if (!win) return DefWindowProc(hwnd, msg, wp, lp);

    switch (msg) {
        case WM_SIZE:
            win->width  = LOWORD(lp);
            win->height = HIWORD(lp);
            if (win->resize_callback)
                win->resize_callback(win, win->width, win->height);
            break;

        case WM_CLOSE:
            win->should_close = 1;
            if (win->close_callback)
                win->close_callback(win);
            break;

        case WM_KEYDOWN:
        case WM_KEYUP:
            if (win->key_callback)
                win->key_callback(win, (int)wp, msg == WM_KEYDOWN ? 1 : 0);
            break;

        case WM_MOUSEMOVE:
            win->mouse_x = (double)GET_X_LPARAM(lp);
            win->mouse_y = (double)GET_Y_LPARAM(lp);
            if (win->mouse_pos_callback)
                win->mouse_pos_callback(win, win->mouse_x, win->mouse_y);
            break;

        case WM_LBUTTONDOWN: case WM_LBUTTONUP:
            if (win->mouse_btn_callback)
                win->mouse_btn_callback(win, 1, msg == WM_LBUTTONDOWN ? 1 : 0);
            break;

        case WM_RBUTTONDOWN: case WM_RBUTTONUP:
            if (win->mouse_btn_callback)
                win->mouse_btn_callback(win, 2, msg == WM_RBUTTONDOWN ? 1 : 0);
            break;

        case WM_MBUTTONDOWN: case WM_MBUTTONUP:
            if (win->mouse_btn_callback)
                win->mouse_btn_callback(win, 3, msg == WM_MBUTTONDOWN ? 1 : 0);
            break;

        case WM_MOUSEWHEEL:
            if (win->scroll_callback)
                win->scroll_callback(win, 0.0, (double)GET_WHEEL_DELTA_WPARAM(wp) / WHEEL_DELTA);
            break;

        case WM_MOUSEHWHEEL:
            if (win->scroll_callback)
                win->scroll_callback(win, (double)GET_WHEEL_DELTA_WPARAM(wp) / WHEEL_DELTA, 0.0);
            break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

UWXX_Platform* platform_init(UWXX* win, const char* title)
{
    UWXX_Platform* p = (UWXX_Platform*)calloc(1, sizeof(UWXX_Platform));
    if (!p) return nullptr;

    p->hinstance = GetModuleHandle(nullptr);

    WNDCLASSA wc = {};
    wc.lpfnWndProc   = wnd_proc;
    wc.hInstance     = p->hinstance;
    wc.lpszClassName = "UCXX_Window";
    RegisterClassA(&wc);

    p->hwnd = CreateWindowExA(
        0, "UCXX_Window", title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        win->width, win->height,
        nullptr, nullptr, p->hinstance, nullptr
    );

    if (!p->hwnd) { free(p); return nullptr; }

    SetWindowLongPtr(p->hwnd, GWLP_USERDATA, (LONG_PTR)win);
    ShowWindow(p->hwnd, SW_SHOW);

    return p;
}

void platform_destroy(UWXX* win)
{
    if (!win->platform) return;
    DestroyWindow(win->platform->hwnd);
    free(win->platform);
    win->platform = nullptr;
}

void platform_poll_events(UWXX* win)
{
    (void)win;
    MSG msg;
    while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}