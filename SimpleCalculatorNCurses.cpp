#include <ncurses.h>
#include <string.h>
#include <fstream>
#include <iostream>

/**
 * @author real0x0a1 (Ali)
 * @file SimpleCalculatorNCurses.cpp
 * @brief A simple calculator program using NCurses library.
 */

int main() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    int highlight = 0;
    const int NUM_OPTIONS = 5;
    const char *options[NUM_OPTIONS] = {
        "Addition",
        "Subtraction",
        "Multiplication",
        "Division",
        "Exit"
    };

    int y, x;
    getmaxyx(stdscr, y, x);
    int center_y = y/2 - NUM_OPTIONS/2;

    const char *additionPrompt = "Enter two numbers: ";
    const char *subtractionPrompt = "Enter two numbers: ";
    const char *multiplicationPrompt = "Enter two numbers: ";
    const char *divisionPrompt = "Enter two numbers: ";

    while(1) {
        clear();
        for(int i = 0; i < NUM_OPTIONS; i++) {
            move(center_y + i, (x - strlen(options[i]))/2);
            if(i == highlight) {
                attron(A_STANDOUT | COLOR_PAIR(1));
            }
            printw("%s\n", options[i]);
            attroff(A_STANDOUT | COLOR_PAIR(1));
        }
        refresh();

        int ch = getch();
        switch(ch) {
            case KEY_UP:
                highlight = (highlight + NUM_OPTIONS - 1) % NUM_OPTIONS;
                break;
            case KEY_DOWN:
                highlight = (highlight + 1) % NUM_OPTIONS;
                break;
            case 10: // Enter key
                switch(highlight) {
                    case 0:
                    {
                        int a, b;
                        printw("%s", additionPrompt);
                        refresh();
                        scanw("%d %d", &a, &b);
                        printw("Addition is: %d\n", a + b);
                        refresh();
                        getch();
                        break;
                    }
                    case 1:
                    {
                        int a, b;
                        printw("%s", subtractionPrompt);
                        refresh();
                        scanw("%d %d", &a, &b);
                        printw("Difference is: %d\n", a - b);
                        refresh();
                        getch();
                        break;
                    }
                    case 2:
                    {
                        int a, b;
                        printw("%s", multiplicationPrompt);
                        refresh();
                        scanw("%d %d", &a, &b);
                        printw("Product is: %d\n", a * b);
                        refresh();
                        getch();
                        break;
                    }
                    case 3:
                    {
                        int a, b;
                        printw("%s", divisionPrompt);
                        refresh();
                        scanw("%d %d", &a, &b);
                        if (b == 0) {
                            printw("Error: Division by zero.\n");
                        } else {
                            printw("Quotient is: %f\n", (float)a / b);
                        }
                        refresh();
                        getch();
                        break;
                    }
                    case 4:
                        endwin();
                        return 0;
                }
                break;
        }
    }

    endwin();
    return 0;
}
