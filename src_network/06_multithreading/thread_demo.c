//
// Created by Prateek Agarwal on 25/5/20.
//

#include <pthread.h>
#include <stdio.h>

void *func(void *arg) {
  printf("Child thread says %s\n", (char *) arg);
  pthread_exit((void *) 99);
}

int main() {
  pthread_t handle;
  int exitcode;

  pthread_create(&handle, NULL, func, "Hello World!");
  printf("primary thread says hello!\n");
  pthread_join(handle, (void **) &exitcode);
  printf("exit code %d\n", exitcode);
}