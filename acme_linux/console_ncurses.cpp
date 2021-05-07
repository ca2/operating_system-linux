//
// Created by camilo on 01/05/2021. 00:11 BRT <3TBS_!!
//
// apt install ncurses-dev
// dnf install ncurses-devel
#include <ncurses.h>
#include "acme/os/_const_console.h"


void __console_init()
{

   initscr();
   raw();
   noecho();
   keypad(stdscr, true);
   start_color();

   init_color(COLOR_WHITE, 1000, 1000, 1000);
   init_color(COLOR_RED, 1000, 0, 0);
   init_color(COLOR_GREEN, 0, 0, 1000);
   init_color(COLOR_BLUE, 0, 0, 500);
   init_color(COLOR_CYAN, 0, 1000, 1000);
   init_color(COLOR_MAGENTA, 1000, 0, 1000);
   init_color(COLOR_YELLOW, 1000, 1000, 0);
   init_color(COLOR_BLACK, 0, 0, 0);

   init_pair(e_dos_color_foreground_white, COLOR_WHITE, COLOR_BLACK);
   init_pair(e_dos_color_foreground_red, COLOR_RED, COLOR_BLACK);
   init_pair(e_dos_color_foreground_blue, COLOR_GREEN, COLOR_BLACK);
   init_pair(e_dos_color_foreground_dark_blue, COLOR_BLUE, COLOR_BLACK);
   init_pair(e_dos_color_foreground_cyan, COLOR_CYAN, COLOR_BLACK);
   init_pair(e_dos_color_foreground_magenta, COLOR_MAGENTA, COLOR_BLACK);
   init_pair(e_dos_color_foreground_yellow, COLOR_YELLOW, COLOR_BLACK);
   init_pair(e_dos_color_foreground_black, COLOR_BLACK, COLOR_BLACK);


}


void __console_term()
{

   endwin();

}



void __console_set_cursor_position(int line, int column)
{

   move(line, column);

}


void __console_set_text_color(int color)
{

   attroff(COLOR_PAIR(color));

}


void __console_write(const char * psz)
{

   printw(psz);
   refresh();

}

