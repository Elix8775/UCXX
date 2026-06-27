#include "../Monitor.h"
#include "../../Platform/Platform.h"

UWXX_Monitor monitor_get_primary(void) {
    return platform_monitor_get_primary();
}

UWXX_Monitor* monitor_get_all(int* count) {
    return platform_monitor_get_all(count);
}

void window_set_fullscreen(UWXX* win, UWXX_Monitor* monitor) {
    win->is_fullscreen = 1;
    platform_set_fullscreen(win, monitor);
}

void window_set_windowed(UWXX* win, int x, int y, int width, int height) {
    win->is_fullscreen = 0;
    platform_set_windowed(win, x, y, width, height);
}

int window_is_fullscreen(UWXX* win) {
    return win->is_fullscreen;
}