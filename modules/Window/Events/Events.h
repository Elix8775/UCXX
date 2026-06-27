#ifndef UCXX_WINDOW_EVENTS_H
#define UCXX_WINDOW_EVENTS_H

#include "../Init/Init.h"

typedef void (*UWXX_KeyCallback)      (UWXX*, int key, int action);
typedef void (*UWXX_ResizeCallback)   (UWXX*, int w, int h);
typedef void (*UWXX_CloseCallback)    (UWXX*);
typedef void (*UWXX_MouseBtnCallback) (UWXX*, int button, int action);
typedef void (*UWXX_MousePosCallback) (UWXX*, double x, double y);
typedef void (*UWXX_ScrollCallback)   (UWXX*, double dx, double dy);

void window_poll_events(UWXX* win);

void window_set_key_callback   (UWXX* win, UWXX_KeyCallback cb);
void window_set_resize_callback(UWXX* win, UWXX_ResizeCallback cb);
void window_set_close_callback (UWXX* win, UWXX_CloseCallback cb);

void window_set_mouse_btn_callback(UWXX* win, UWXX_MouseBtnCallback cb);
void window_set_mouse_pos_callback(UWXX* win, UWXX_MousePosCallback cb);
void window_set_scroll_callback   (UWXX* win, UWXX_ScrollCallback cb);

void window_get_mouse_pos(UWXX* win, double* x, double* y);

#endif