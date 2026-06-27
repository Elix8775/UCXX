#ifndef __linux__
#error "x11.cpp compilation error"
#endif

#include <X11/Xlib.h>
#include <stdlib.h>
#include <X11/extensions/Xrandr.h>
#include <cstring>
#include "../Platform.h"

UWXX_Platform* platform_init(UWXX* win, const char* title) 
{
    UWXX_Platform* p = (UWXX_Platform*)calloc(1, sizeof(UWXX_Platform));
    if (!p) return nullptr;

    p->display = XOpenDisplay(nullptr);
    if (!p->display) { free(p); return nullptr; }

    int screen = DefaultScreen(p->display);

    p->window = XCreateSimpleWindow(
        p->display,
        RootWindow(p->display, screen),
        0, 0,
        win->width, win->height,
        0,
        BlackPixel(p->display, screen),
        BlackPixel(p->display, screen)
    );

    XSelectInput(p->display, p->window,
        ExposureMask       |
        KeyPressMask       |
        KeyReleaseMask     |
        ButtonPressMask    |
        ButtonReleaseMask  |
        PointerMotionMask  |
        StructureNotifyMask
    );

    p->wm_delete = XInternAtom(p->display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(p->display, p->window, &p->wm_delete, 1);

    XStoreName(p->display, p->window, title);
    XMapWindow(p->display, p->window);
    XFlush(p->display);

    return p;
}

void platform_destroy(UWXX* win) 
{
    if (!win->platform) return;
    XDestroyWindow(win->platform->display, win->platform->window);
    XCloseDisplay(win->platform->display);
    free(win->platform);
    win->platform = nullptr;
}

void platform_cursor_hide(UWXX* win) 
{
    UWXX_Platform* p = win->platform;

    static char data[1] = {0};
    Pixmap blank = XCreateBitmapFromData(p->display, p->window, data, 1, 1);
    XColor dummy = {};
    Cursor invisible = XCreatePixmapCursor(p->display, blank, blank, &dummy, &dummy, 0, 0);
    XDefineCursor(p->display, p->window, invisible);
    XFreeCursor(p->display, invisible);
    XFreePixmap(p->display, blank);
}

void platform_cursor_show(UWXX* win) 
{
    UWXX_Platform* p = win->platform;
    XUndefineCursor(p->display, p->window);
}

void platform_cursor_set_pos(UWXX* win, double x, double y) 
{
    UWXX_Platform* p = win->platform;
    XWarpPointer(p->display, None, p->window, 0, 0, 0, 0, (int)x, (int)y);
    XFlush(p->display);
}

void platform_poll_events(UWXX* win) 
{
    UWXX_Platform* p = win->platform;

    XEvent event;
    while (XPending(p->display)) {
        XNextEvent(p->display, &event);

        switch (event.type) {
            case ClientMessage:
                if ((Atom)event.xclient.data.l[0] == p->wm_delete) 
                {
                    win->should_close = 1;
                    if (win->close_callback)
                        win->close_callback(win);
                }
                break;

            case ConfigureNotify:
                if (event.xconfigure.width  != win->width ||
                    event.xconfigure.height != win->height) 
                    {
                    win->width  = event.xconfigure.width;
                    win->height = event.xconfigure.height;
                    if (win->resize_callback)
                        win->resize_callback(win, win->width, win->height);
                }
                break;

            case KeyPress:
            case KeyRelease:
                if (win->key_callback)
                    win->key_callback(win,
                        (int)event.xkey.keycode,
                        event.type == KeyPress ? 1 : 0);
                break;

            case MotionNotify: {
                double cx = win->width  / 2.0;
                double cy = win->height / 2.0;

                if (win->cursor_locked) {
                    double dx = event.xmotion.x - cx;
                    double dy = event.xmotion.y - cy;
                    if (dx != 0.0 || dy != 0.0) {
                        win->mouse_x = dx;
                        win->mouse_y = dy;
                        if (win->mouse_pos_callback)
                            win->mouse_pos_callback(win, dx, dy);
                        XWarpPointer(p->display, None, p->window, 0, 0, 0, 0, (int)cx, (int)cy);
                        XFlush(p->display);
                    }
                } else {
                    win->mouse_x = (double)event.xmotion.x;
                    win->mouse_y = (double)event.xmotion.y;
                    if (win->mouse_pos_callback)
                        win->mouse_pos_callback(win, win->mouse_x, win->mouse_y);
                }
                break;
            }

            case ButtonPress:
            case ButtonRelease: {
                int action = event.type == ButtonPress ? 1 : 0;
                if (event.xbutton.button == Button4) {
                    if (win->scroll_callback)
                        win->scroll_callback(win, 0.0, 1.0);
                } else if (event.xbutton.button == Button5) {
                    if (win->scroll_callback)
                        win->scroll_callback(win, 0.0, -1.0);
                } else {
                    if (win->mouse_btn_callback)
                        win->mouse_btn_callback(win, (int)event.xbutton.button, action);
                }
                break;
            }
        }
    }
}

UWXX_Monitor platform_monitor_get_primary(void) {
    Display* dpy = XOpenDisplay(nullptr);
    UWXX_Monitor mon = {};

    int screen = DefaultScreen(dpy);
    mon.x      = 0;
    mon.y      = 0;
    mon.width  = DisplayWidth (dpy, screen);
    mon.height = DisplayHeight(dpy, screen);

    XRRScreenConfiguration* sc = XRRGetScreenInfo(dpy, RootWindow(dpy, screen));
    if (sc) {
        mon.refresh_rate = (int)XRRConfigCurrentRate(sc);
        XRRFreeScreenConfigInfo(sc);
    }

    strncpy(mon.name, "Primary", 255);
    XCloseDisplay(dpy);
    return mon;
}

UWXX_Monitor* platform_monitor_get_all(int* count) {
    Display* dpy = XOpenDisplay(nullptr);
    int screen   = DefaultScreen(dpy);

    XRRMonitorInfo* xmons = XRRGetMonitors(dpy, RootWindow(dpy, screen), True, count);
    UWXX_Monitor* mons    = (UWXX_Monitor*)calloc(*count, sizeof(UWXX_Monitor));

    for (int i = 0; i < *count; i++) {
        mons[i].x      = xmons[i].x;
        mons[i].y      = xmons[i].y;
        mons[i].width  = xmons[i].width;
        mons[i].height = xmons[i].height;
        char* n = XGetAtomName(dpy, xmons[i].name);
        if (n) { strncpy(mons[i].name, n, 255); XFree(n); }
    }

    XRRFreeMonitors(xmons);
    XCloseDisplay(dpy);
    return mons;
}

void platform_set_fullscreen(UWXX* win, UWXX_Monitor* monitor) {
    (void)monitor;
    UWXX_Platform* p = win->platform;

    Atom wm_state     = XInternAtom(p->display, "_NET_WM_STATE", False);
    Atom wm_fullscreen = XInternAtom(p->display, "_NET_WM_STATE_FULLSCREEN", False);

    XEvent ev = {};
    ev.type                 = ClientMessage;
    ev.xclient.window       = p->window;
    ev.xclient.message_type = wm_state;
    ev.xclient.format       = 32;
    ev.xclient.data.l[0]    = 1; 
    ev.xclient.data.l[1]    = (long)wm_fullscreen;

    XSendEvent(p->display,
        RootWindow(p->display, DefaultScreen(p->display)),
        False,
        SubstructureRedirectMask | SubstructureNotifyMask,
        &ev);
    XFlush(p->display);
}

void platform_set_windowed(UWXX* win, int x, int y, int width, int height) {
    UWXX_Platform* p = win->platform;

    Atom wm_state      = XInternAtom(p->display, "_NET_WM_STATE", False);
    Atom wm_fullscreen = XInternAtom(p->display, "_NET_WM_STATE_FULLSCREEN", False);

    XEvent ev = {};
    ev.type                 = ClientMessage;
    ev.xclient.window       = p->window;
    ev.xclient.message_type = wm_state;
    ev.xclient.format       = 32;
    ev.xclient.data.l[0]    = 0;
    ev.xclient.data.l[1]    = (long)wm_fullscreen;

    XSendEvent(p->display,
        RootWindow(p->display, DefaultScreen(p->display)),
        False,
        SubstructureRedirectMask | SubstructureNotifyMask,
        &ev);

    XMoveResizeWindow(p->display, p->window, x, y, width, height);
    XFlush(p->display);
}