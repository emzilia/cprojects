#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

void init_window();
void print_title();
void print_map(char arr[][28], int rows, int columns);
void print_userinfo();
void print_time();
void print_actions();
void print_event(char* text);
void print_event_args(char* text, char* args);

extern WINDOW* win;
extern int debug;
extern char map[8][28];
extern int rows;
extern int columns;

#endif
