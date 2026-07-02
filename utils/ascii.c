#include "ascii.h"
#include <ncurses.h>

char str_second[3], str_minute[3], str_hour[3];
char buffer[9] = "";
char *colon[5], *h1[5], *h2[5], *m1[5], *m2[5], *s1[5], *s2[5];
char *ascii_all[5] = {"","","","",""};

void ascii_renderer(char nominal, char * rendered[]){
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

void ascat(char *str){
  ascii_renderer(str[0], h1);
  ascii_renderer(str[1], h2);
  ascii_renderer(str[2], colon);
  ascii_renderer(str[3], m1);
  ascii_renderer(str[4], m2);
  ascii_renderer(str[6], s1);
  ascii_renderer(str[7], s2);}

void display(unsigned int seconds){
  unsigned int minutes = (unsigned int)seconds/60, hours = (unsigned int)seconds/3600;
  snprintf(str_hour, 2 + 1, "%u", hours % 100);       // |
  snprintf(str_minute, 2 + 1, "%02u", minutes % 60);  // | converting unsigned integer into string
  snprintf(str_second, 2 + 1, "%02u", seconds % 60);  // |
  strcat(buffer, str_hour);
  strcat(buffer, ":");
  strcat(buffer, str_minute);
  strcat(buffer, ":");
  strcat(buffer, str_second);   // the final result of concatination process
  ascat(buffer);
  if (LINES < 14 || COLS < 50) {
    mvaddstr(LINES/2, (COLS - 48)/2, buffer); // entering the fallback mode
  }else {
    for (int i = 0; i < 5; i++) {
      mvprintw((LINES/2) - 2 + i, (COLS - 48)/2,"%s%s%s%s%s%s%s%s\n", h1[i], h2[i], colon[i], m1[i], m2[i], colon[i], s1[i], s2[i]);
    }
  }
  refresh();
  strcpy(buffer, ""); // emptying the buffer
}
