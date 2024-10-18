#include <ncurses.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "game_of_life.h"
int main()
{
	MEVENT event;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	mouseinterval(3);
	mousemask(ALL_MOUSE_EVENTS, NULL);

	initGame();

	while(true) {
		displayGeneration();

		int ch = getch();
		switch(ch) {
		case KEY_MOUSE:
			if(getmouse(&event) == OK) {
				if(event.bstate & BUTTON1_PRESSED) {
					int row = event.y;
					int col = event.x;
					if(row >= 0 && row < ROWS && col >= 0 && col < COL) {
						grid[row][col] = !grid[row][col]; 
					}
				}
			}
			break;
		case 'q':
		case 'Q':
			goto end;
		default:
			nextGeneration();
			break;
		}
	}
end:
	endwin();
	return 0;
}

