//
// Created by Prateek Agarwal on 24/5/20.
//

#include <stdio.h>
#include <sys/signal.h>
#include <unistd.h>
#include <errno.h>

void handler(int signum) { printf("Received signal : %d\n", signum); }

int main() {
  struct sigaction action;
  int n, p[2];
  char buf[1000];

  pipe(p);

  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = SA_RESTART;

  sigaction(SIGINT, &action, NULL);

  while(1) {
    n = read(p[0], buf, 1000);
    printf("read returned %d, errno %d\n", n, errno);
  }
}