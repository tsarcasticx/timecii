#include "helper.h"
#include <stdio.h>

void show_help(){
  char *help[5] = {
  "ASCII TIMER",
  "===========",
  "This program has an argument in maximum",
  "just run the program if you want to use this as a stopwatch",
  "add an argument of positive number if you want to set a timer",
  };
  for (int i = 0; i < 5; i++) {
    printf("%s\n", help[i]);
  }
}
