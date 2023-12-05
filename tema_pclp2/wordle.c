#include <curses.h>

int main() {
    initscr();
    printw("-WORDLE-");
    refresh();
    char word[100];
    getstr(word);
    endwin();
    return 0;
}
