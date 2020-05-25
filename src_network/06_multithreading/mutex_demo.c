//
// Created by Prateek Agarwal on 25/5/20.
//

#include <pthread.h>
#include <stdio.h>

static int global_var = 0;
pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;

void *func(__attribute__((unused)) void *arg) {
  int local_var, i;

  for (i = 0; i < 1000000; i++) {
    pthread_mutex_lock(&mylock);
    local_var = global_var;
    local_var++;
    global_var = local_var;
    pthread_mutex_unlock(&mylock);
  }

  return NULL;
}

int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, func, NULL);
  pthread_create(&t2, NULL, func, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("global_var = %d\n", global_var);
}