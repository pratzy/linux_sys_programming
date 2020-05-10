#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;
    if (fork())
    {
        // In parent
        printf("Parent waiting for child...\n");
        wait(&status);
        if (WIFEXITED(status))
            printf("Child exited normally, exit status = %d\n", WIFEXITED(status));
        if (WIFSIGNALED(status))
            printf("Child terminated by signal %d\n", WTERMSIG(status));
    }
    else
    {
        printf("Child running with PID %d\n", getpid());
        sleep(5);
        exit(3);
    }
}