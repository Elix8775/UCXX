#ifndef UCXX_WINDOW_PLATFORM_H
#define UCXX_WINDOW_PLATFORM_H

#include "../Init/Init.h"
#include "../Monitor/Monitor.h"
#include <X11/Xlib.h>

struct UWXX_Platform {
    Display* display;
    Window   window;
    Atom     wm_delete;
};

UWXX_Platform* platform_init(UWXX* win, const char* title);
UWXX_Monitor   platform_monitor_get_primary(void);
UWXX_Monitor*  platform_monitor_get_all(int* count);
void           platform_set_fullscreen(UWXX* win, UWXX_Monitor* monitor);
void           platform_set_windowed  (UWXX* win, int x, int y, int width, int height);
void           platform_destroy(UWXX* win);
void           platform_poll_events(UWXX* win);
void           platform_cursor_show   (UWXX* win);
void           platform_cursor_hide   (UWXX* win);
void           platform_cursor_set_pos(UWXX* win, double x, double y);

#endif