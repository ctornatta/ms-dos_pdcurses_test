#include <curses.h>

int main() {
    initscr();              // Start curses mode
    cbreak();               // Disable line buffering
    noecho();               // Don't echo typed characters
    keypad(stdscr, TRUE);   // Enable arrow keys and F1-F12
    curs_set(0);            // Hide the cursor

    // Set up color if available
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_BLUE);
        attron(COLOR_PAIR(1));
    }

    // Draw a border and some text
    box(stdscr, 0, 0);
    mvprintw(1, 2, "PDCurses Test - Press Q to quit");

    refresh();

    int ch;
    while ((ch = getch()) != 'q' && ch != 'Q') {
        mvprintw(3, 2, "You pressed: %d (char: %c)    ", ch, ch);
        refresh();
    }

    endwin();  // End curses mode
    return 0;
}

