#ifndef UCXX_WINDOW_MONITOR_H
#define UCXX_WINDOW_MONITOR_H

#include "../Init/Init.h"

typedef struct {
    int x, y;
    int width, height;
    int refresh_rate;
    char name[256];
} UWXX_Monitor;

UWXX_Monitor  monitor_get_primary(void);
UWXX_Monitor* monitor_get_all(int* count);

void window_set_fullscreen  (UWXX* win, UWXX_Monitor* monitor);
void window_set_windowed    (UWXX* win, int x, int y, int width, int height);
int  window_is_fullscreen   (UWXX* win);

#endif