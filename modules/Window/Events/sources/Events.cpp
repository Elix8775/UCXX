#include "../Events.h"
#include "../../Platform/Platform.h"
#include <stdlib.h>

void window_poll_events(UWXX* win)                                     { platform_poll_events(win);    }
void window_set_key_callback(UWXX* win, UWXX_KeyCallback cb)           { win->key_callback       = cb; }
void window_set_resize_callback(UWXX* win, UWXX_ResizeCallback cb)     { win->resize_callback    = cb; }
void window_set_close_callback(UWXX* win, UWXX_CloseCallback cb)       { win->close_callback     = cb; }
void window_set_mouse_btn_callback(UWXX* win, UWXX_MouseBtnCallback cb){ win->mouse_btn_callback = cb; }
void window_set_mouse_pos_callback(UWXX* win, UWXX_MousePosCallback cb){ win->mouse_pos_callback = cb; }
void window_set_scroll_callback(UWXX* win, UWXX_ScrollCallback cb)     { win->scroll_callback    = cb; }

void window_get_mouse_pos(UWXX* win, double* x, double* y) 
{
    *x = win->mouse_x;
    *y = win->mouse_y;
}