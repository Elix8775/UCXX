#include "../Init.h"
#include "../../Platform/Platform.h"
#include <stdlib.h>
#include <string.h>

UWXX* create_window(int width, int height, const char* title) 
{
    UWXX* win = (UWXX*)calloc(1, sizeof(UWXX));
    if (!win) return nullptr;

    win->width  = width;
    win->height = height;
    strncpy(win->title, title, 255);

    win->platform = platform_init(win, title);
    if (!win->platform) {
        free(win);
        return nullptr;
    }
    return win;
}

void destroy_window(UWXX* win) 
{
    if (!win) return;
    platform_destroy(win);
    free(win);
}

int window_should_close(UWXX* win) 
{
    return win->should_close;
}