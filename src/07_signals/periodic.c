//
// Created by Prateek Agarwal on 24/5/20.
//
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

char *p, buffer[10000];

void handler() {
  int fd;

  fd = open("buffer.save", O_RDWR | O_CREAT | O_TRUNC, 0644);
  write(fd, buffer, p - buffer);
  close(fd);
  alarm(10);
}

int main() {
  int count;
  struct sigaction action;
  p = buffer;

  // Establish SIGALRM handler
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = SA_RESTART;
  sigaction(SIGALRM, &action, NULL);
  alarm(10);

  while ((count = read(0, p, 200))) p += count;
}