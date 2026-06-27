#include "ucxx.h"

void on_mouse_pos(UWXX* win, double x, double y) {
    (void)win;
    printf("delta: %.0f %.0f\n", x, y);
}

int main() {
    UWXX* win = create_window(800, 600, "UCXX - Cursor Test");
    window_set_mouse_pos_callback(win, on_mouse_pos);
    window_cursor_lock(win);

    while (!window_should_close(win)) {
        window_poll_events(win);
    }

    destroy_window(win);
    return 0;
}