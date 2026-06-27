#ifndef UCXX_WINDOW_MONITOR_TYPES_H
#define UCXX_WINDOW_MONITOR_TYPES_H

typedef struct {
    int  x, y;
    int  width, height;
    int  refresh_rate;
    char name[256];
} UWXX_Monitor;

#endif