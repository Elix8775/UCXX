#ifndef UCXX_WINDOW_CURSOR_H
#define UCXX_WINDOW_CURSOR_H

#include "../Init/Init.h"

void window_cursor_show  (UWXX* win);
void window_cursor_hide  (UWXX* win);
void window_cursor_lock  (UWXX* win);
void window_cursor_unlock(UWXX* win);
void window_cursor_set_pos(UWXX* win, double x, double y);

#endif