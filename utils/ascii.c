#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include "ascii.h"

void initascii(char nominal, char * rendered[]){
  // char *
  switch (nominal) {
  case '0':
    rendered[0] = " ███  ";
    rendered[1] = "█   █ ";
    rendered[2] = "█   █ ";
    rendered[3] = "█   █ ";
    rendered[4] = " ███  ";
    break;
  case '1':
    rendered[0] = " █    ";
    rendered[1] = "██    ";
    rendered[2] = " █    ";
    rendered[3] = " █    ";
    rendered[4] = "███   ";
    break;
  case '2':
    rendered[0] = " ███  ";
    rendered[1] = "█   █ ";
    rendered[2] = "  ██  ";
    rendered[3] = " █    ";
    rendered[4] = "█████ ";
    break;
  case '3':
    rendered[0] = "█████ ";
    rendered[1] = "   █  ";
    rendered[2] = "  ██  ";
    rendered[3] = "█   █ ";
    rendered[4] = " ███  ";
    break;
  case '4':
    rendered[0] = "   █  ";
    rendered[1] = "  ██  ";
    rendered[2] = " █ █  ";
    rendered[3] = "█████ ";
    rendered[4] = "   █  ";
    break;
  case '5':
    rendered[0] = "█████ ";
    rendered[1] = "█     ";
    rendered[2] = "████  ";
    rendered[3] = "    █ ";
    rendered[4] = "████  ";
    break;
  case '6':
    rendered[0] = " ███  ";
    rendered[1] = "█     ";
    rendered[2] = "████  ";
    rendered[3] = "█   █ ";
    rendered[4] = " ███  ";
    break;
  case '7':
    rendered[0] = "█████ ";
    rendered[1] = "    █ ";
    rendered[2] = "   █  ";
    rendered[3] = "  █   ";
    rendered[4] = " █    ";
    break;
  case '8':
    rendered[0] = " ███  ";
    rendered[1] = "█   █ ";
    rendered[2] = " ███  ";
    rendered[3] = "█   █ ";
    rendered[4] = " ███  ";
    break;
  case '9':
    rendered[0] = " ███  ";
    rendered[1] = "█   █ ";
    rendered[2] = " ████ ";
    rendered[3] = "    █ ";
    rendered[4] = " ███  ";
    break;
  case ':':
    rendered[0] = "      ";
    rendered[1] = " ███  ";
    rendered[2] = "      ";
    rendered[3] = " ███  ";
    rendered[4] = "      ";
    break;
  default:
      break;
  }
}

void fallback(){
  //
}

void interface(unsigned int hours, unsigned int minutes, unsigned int seconds){
  char str_hour[3]; snprintf(str_hour, 2 + 1, "%u", hours % 100);
  char str_minute[3]; snprintf(str_minute, 2 + 1, "%02u", minutes % 60);
  char str_second[3]; snprintf(str_second, 2 + 1, "%02u", seconds % 60);
  char colon[5], h1[5], h2[5], m1[5], m2[5], s1[5], s2[5];
  char str_all[9] = "";
  strcat(str_all, str_hour);
  strcat(str_all, ":");
  strcat(str_all, str_minute);
  strcat(str_all, ":");
  strcat(str_all, str_second);


  struct winsize win;
  ioctl(0, TIOCGWINSZ, &win);
  int terminal_height = win.ws_row, terminal_width = win.ws_col;

}
