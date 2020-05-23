#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
  int status;
  int a, b, c;

  if (fork()) {
    // Parent
    wait(&status);
    if (WIFEXITED(status))
      printf("Child exited normally with exit status %d\n",
             WEXITSTATUS(status));
    if (WIFSIGNALED(status))
      printf("Child exited on signal %d: %s\n", WTERMSIG(status),
             strsignal(WTERMSIG(status)));
  } else {
    // Child
    printf("Child PID=%d\n", getpid());

    // Simulate SIGSEGV
    // *(int *)0 = 99;

    //Pause and send SIGTERM to child PID
    pause();

    sleep(3);
    exit(5);
  }
}