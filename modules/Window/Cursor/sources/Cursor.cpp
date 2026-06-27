#include "../Cursor.h"
#include "../../Platform/Platform.h"

void window_cursor_show(UWXX* win) 
{
    win->cursor_hidden = 0;
    platform_cursor_show(win);
}

void window_cursor_hide(UWXX* win) 
{
    win->cursor_hidden = 1;
    platform_cursor_hide(win);
}

void window_cursor_lock(UWXX* win) 
{
    win->cursor_locked = 1;
    platform_cursor_hide(win);
}

void window_cursor_unlock(UWXX* win) 
{
    win->cursor_locked = 0;
    platform_cursor_show(win);
}

void window_cursor_set_pos(UWXX* win, double x, double y) 
{
    platform_cursor_set_pos(win, x, y);
}