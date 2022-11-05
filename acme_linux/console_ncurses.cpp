//
// Created by camilo on 01/05/2021. 00:11 BRT <3TBS_!!
//
// apt install ncurses-dev
// dnf install ncurses-devel
#undef OK
#include <ncurses.h>
#include <limits.h>
#include "acme/_start.h"
#include "acme/operating_system/_const_console.h"
#include "acme/constant/status.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sstream>


void throw_exception(enum_status estatus);
::enum_status _errno_status(int nErrno);


int __console_init(void ** ppscreen, void ** ppwindow, FILE * pfileOut, FILE * pfileIn, int cols, int lines)
{

   pthread_mutex_t m;

   if (pthread_mutex_init(&m, NULL) != 0)
   {

      printf("\n mutex init has failed\n");

      return 1;

   }

   pthread_mutex_lock(&m);

   if(fork() == 0)
   {

      int pt = posix_openpt(O_RDWR);

      if (pt == -1)
      {

         printf("Could not open pseudo terminal.\n");

         return -1;

      }

      char * ptname = ptsname(pt);

      if (!ptname)
      {

         std::cerr << "Could not get pseudo terminal device name.\n";

         close(pt);

         return EXIT_FAILURE;

      }

      if (unlockpt(pt) == -1)
      {

         std::cerr << "Could not get pseudo terminal device name.\n";

         close(pt);

         return EXIT_FAILURE;

      }

      std::ostringstream oss;

      std::string str = getenv("SHELL");

      oss << str << " -S" << (strrchr(ptname, '/') + 1) << "/" << pt << " &";

      auto iError = system(oss.str().c_str());

      if(iError != 0)
      {

         throw_exception(::error_failed);

      }

      int xterm_fd = open(ptname, O_RDWR);

      char c;

      do
      {

         auto iRead = read(xterm_fd, &c, 1);

         if(iRead < 0)
         {

            auto iError = errno;

            auto estatus = _errno_status(iError);

            throw_exception(estatus);

         }

      }
      while (c != '\n');

      if (dup2(pt, 1) < 0)
      {

         std::cerr << "Could not redirect standard output.\n";

         close(pt);

         return EXIT_FAILURE;

      }

      if (dup2(pt, 2) < 0)
      {

         std::cerr << "Could not redirect standard error output.\n";

         close(pt);

         return EXIT_FAILURE;

      }

      std::cout << "This should appear on the xterm." << std::endl;

      std::cerr << "So should this.\n";

      std::cin.ignore(1);

      //close(pt);

      const char * pszTermName = getenv("TERM");

      if (pszTermName == nullptr)
      {

         pszTermName = "vt100";

      }

      auto pscreen = newterm(pszTermName, pfileOut, pfileIn);

      set_term((SCREEN *) pscreen);

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

      auto pwindow = newwin(lines, cols, 0, 0);

      *ppscreen = pscreen;
      *ppwindow = pwindow;

      pthread_mutex_unlock(&m);

      while(true)
      {

         sleep(1);

      }

   }
   else
   {

      pthread_mutex_lock(&m);
      pthread_mutex_unlock(&m);

      printf("finished child");

   }

   return 0;

}


void __console_term(void * pscreen)
{

   delscreen((SCREEN *) pscreen);

}



void __console_set_cursor_position(void * pscreen, int line, int column)
{

   set_term((SCREEN *) pscreen);

   move(line, column);

}


void __console_set_text_color(void * pscreen, int color)
{

   set_term((SCREEN *) pscreen);

   attroff(COLOR_PAIR(color));

}


void __console_write(void * pscreen, const char * psz)
{

   set_term((SCREEN *) pscreen);

   printw("%s", psz);

   refresh();

}

