#include "utils/ascii.h"
#include "utils/var.h"
#include "utils/helper.h"

void signalHandler(int sig) {
  printf("\nProcess is terminated: %d hours, %d minutes, and %d seconds\n", hours, minutes, seconds);
  endwin();
  _exit(sig);
}
void backwardCounting(unsigned int durations){
  seconds = durations;
  do {
    signal(SIGINT, signalHandler);
    clear();
    display(seconds);
    sleep(1);
    seconds -= 1;
  } while(seconds > 0);

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
  long durations; // an imitation for unsigned int. I hope you understand
  initscr();
  raw();
  noecho();

  switch (argc) {
    case 1:
      forwardCounting();
      break;
    case 2:
      durations = strtol(argv[1], NULL, 10);
      (durations <= 0) ? show_help() : backwardCounting((unsigned int)durations);
      break;
    default:
      show_help();
      break;
  }

  endwin();
  return 0;
}
