#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int n;

void handler(int signum) {
    printf("Received signal %d, resetting counter to 0.\n", signum);
    n = 0;
}

int main() {
    signal(SIGINT, handler);

    //Ignore these two signals
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);

    printf("PID: %d\n", getpid());
    while (1) {
        printf("Working..%d\n", n++);
        sleep(1);
    }
}