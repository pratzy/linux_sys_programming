//
// Created by Prateek Agarwal on 24/5/20.
//

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>

void timeout_handler(int unused) {
  // Do nothing
}

int t_getnum(int timeout) {
  int n;
  char line[100];
  struct sigaction action;

  action.sa_handler = timeout_handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;// Important
  sigaction(SIGALRM, &action, NULL);

  alarm(timeout);
  n = read(0, line, 100);
  alarm(0);// Cancel alarm if the read is successful
  if (n == -1 && errno == EINTR) return -1;
  n = atoi(line);
  return n;
}


int main() {
  int num;

  while (1) {
    printf("Enter a number: ");
    fflush(stdout);
    if ((num = t_getnum(5)) == -1) printf("Timed out!\n");
    else
      printf("You entered %d\n", num);
  }
}