#include <ncurses.h>
#include <unistd.h>

static const int START_X = 25;
static const int START_Y = 5;
static const int END_X = 55;
static const int END_Y = 15;
static const int DELAY = 600000;
static const int SCROLL = 1;

static const int HEIGHT = END_Y - START_Y;
static const int WIDTH = END_X - START_X;
static const char *COLOR_NAMES[] = {
        "BLACK",
        "RED",
        "GREEN",
        "YELLOW",
        "BLUE",
        "MAGENTA",
        "CYAN",
        "WHITE"
};

int main(int argc, char *argv[]) {
    initscr();
    WINDOW *window = newwin(HEIGHT, WIDTH, START_Y, START_X);
    start_color();
    scrollok(window, true);
    for (short i = 0; i < 8; ++i) {
        for (short j = 0; j < 8; ++j) {
            init_pair(1, i, j);
            wattron(window, COLOR_PAIR(1));
            wprintw(window, "Фон %s; Сим %s\n", COLOR_NAMES[j], COLOR_NAMES[i]);
            wrefresh(window);
            wscrl(window, 0);
            wattroff(window, COLOR_PAIR(1));
            usleep(DELAY);
        }
    }
    wgetch(window);
    endwin();
}