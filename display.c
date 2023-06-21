#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "entities.h"
#include "display.h"
#include "logic.h"

WINDOW *win;
WINDOW *borderwin;

void init_window()
{
	initscr();
	refresh();
	borderwin = newwin(35, 65, 1, 1);
	win = newwin(30, 60, 2, 2);
	noecho();	
	curs_set(0);
	keypad(win, TRUE);
	wborder(borderwin, '|', '|', '=', '=', 'o', 'o', 'o', 'o');
	wrefresh(borderwin);
	wrefresh(win);
	wmove(win, 2, 6);
}

char map[8][28] = {
	"o==========================o",
	"|.....c./^^^^^^^^^^^^^^^t..|",
	"|.t..../........c^^^^^^^...|",
	"|..___/....t.............c.|",
	"|./...c........c...........|",
	"|/.....**t*******..t.......|",
	"|..c..************......t..|",
	"o==========================o"
};
	

int rows = sizeof(map) / sizeof(map[0]);
int columns = sizeof(map[0]) / sizeof(map[0][0]);

void print_title()
{
	wprintw(win,
		"Hello and welcome to Tania!\n\n"
		"The Duke has been gone for three years now,\n"
		"fighting heathens abroad. Unrest grows across the\n"
		"realm as local nobles centralize their power.\n"
	);
	wrefresh(win);

	if (getch() == 'p') debug = 1;
	werase(win);
	wrefresh(win);
}

void print_map(char arr[][28], int rows, int columns) {
	wprintw(win, "  Dutchy of Tania\n");
	for (int r = 0; r < rows; r++) {
		wprintw(win, "  ");
		for (int c = 0; c < columns; c++) {
			if (r == p.y && c == p.x)
				waddch(win, '@');
			else
				wprintw(win, "%c", arr[r][c]);
		}
	waddch(win, '\n'); }
	if (debug) wprintw(win, " %d, %d\n", p.x, p.y);
	set_location();
}

void print_userinfo()
{
    	if (p.intown) wprintw(win, "  %s\n\n", p.location);
    	if (!p.intown) wprintw(win, "  Plains of Castamere\n\n");
	wprintw(win, "  Your title is %s, you have $%i in silver\n", p.title, p.denars);
	wprintw(win, "  You have %zu warriors in your employ\n\n", p.army);	
}

void print_actions()
{
    	wprintw(win, "  Actions:\n");
	if (p.intown) {
	wprintw(win, "  1. Enter city\n  2. Contact nobleman\n  3. Hire local mercenaries\n\n"); 
	} else if (!p.intown) {
	wprintw(win, "  1. Setup fortified camp\n  2. Draft correspondence\n\n\n");
	}
	wprintw(win, "  i. View Inventory\n"); 
	wprintw(win, "  r. View Relations\n"); 
	wprintw(win, "  q. View Current Quests\n");
}