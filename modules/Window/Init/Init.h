#ifndef UCXX_WINDOW_INIT_H
#define UCXX_WINDOW_INIT_H

#include <stdint.h>

typedef struct UWXX_Platform UWXX_Platform;

typedef struct UWXX {
    int    width, height;
    int    should_close;
    int    cursor_hidden;
    int    cursor_locked;
    int    is_fullscreen;
    char   title[256];

    double mouse_x, mouse_y;

    void (*key_callback)      (struct UWXX*, int key, int action);
    void (*resize_callback)   (struct UWXX*, int w, int h);
    void (*close_callback)    (struct UWXX*);
    void (*mouse_btn_callback)(struct UWXX*, int button, int action);
    void (*mouse_pos_callback)(struct UWXX*, double x, double y);
    void (*scroll_callback)   (struct UWXX*, double dx, double dy);

    UWXX_Platform* platform;
} UWXX;

UWXX* create_window(int width, int height, const char* title);
void  destroy_window(UWXX* win);
int   window_should_close(UWXX* win);

#endif