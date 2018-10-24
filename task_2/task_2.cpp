#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int main(int argc, char *argv[]) {
    initscr();            /* Start curses mode 		*/
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();            /* Start color 			*/
    for (int i = 0; i < COLORS; ++i) {
        for (int j = 0; j < COLORS; ++j) {
            init_pair(1, i, j);
            attron(COLOR_PAIR(1));
            print_in_middle(stdscr, 5, 25, 30, "Viola !!! In color ...");
            attroff(COLOR_PAIR(1));
            usleep(600000);
        }
    }
    getch();
    endwin();
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string) {
    int length, x, y;
    float temp;

    if (win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if (startx != 0)
        x = startx;
    if (starty != 0)
        y = starty;
    if (width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length) / 2;
    x = startx + (int) temp;
    mvwprintw(win, y, x, "%s", string);
    refresh();
}