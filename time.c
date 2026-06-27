#include "utils/ascii.h"
#include "utils/helper.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

unsigned int seconds, minutes, hours;
char chars[] = "`^\",:;Il!i~+_-?][}(1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao#MW&8%B@S";

void signalHandler(int sig) {
  printf("\nProcess is terminated in %d hours, %d minutes, and %d seconds\n", hours, minutes, seconds);
  _exit(sig);
}
void backwardCounting(unsigned int durations){
  seconds = durations;
  int i = 0;
  signal(SIGINT, signalHandler);
  do {
    i++;
    minutes = (unsigned int)seconds/60;
    hours = (unsigned int)seconds/3600;
    system("clear");
    printf("%02d:%02d:%02d\n", hours, minutes % 60, seconds % 60);
    sleep(1);
    seconds -= 1;
  } while(i <durations);

  printf("%d\n", durations);
}
void forwardCounting(){
  hours=minutes=seconds=0;
  signal(SIGINT, signalHandler);
  while(1==1) {
    seconds += 1;
    minutes = (seconds % 60 != 0) ? minutes : minutes + 1;
    hours = (seconds % 3600 != 0) ? hours : hours + 1;
    system("clear");
    printf("%02d:%02d:%02d\n", hours, minutes % 60, seconds % 60);
    sleep(1);
  }
}

int main(int argc, char *argv[]) {
  long *durations = malloc(sizeof(long));
  if (durations == NULL) {
    return 1;
  }

  switch (argc) {
    case 1:
      free(durations);
      durations = NULL;
      forwardCounting();
      break;
    case 2:
      *durations = strtol(argv[1], NULL, 10);
      (*durations <= 0) ? show_help() : backwardCounting((unsigned int)*durations);
      free(durations);
      durations = NULL;
      break;
    default:
      show_help();
      break;
  }
  return 0;
}
