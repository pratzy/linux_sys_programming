#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int p[2]; // To hold both ends of the pipe.

    pipe(p);
    if (fork() == 0)
    {
        // In child - Upstream (Producer)
        // Connect stdout to pipe
        dup2(p[1], 1);
        close(p[0]);
        execlp("ls", "ls", (char *)0);
    }
    // Parent - Downstream (Consumer)
    // Connect stdin to pipe
    dup2(p[0], 0);
    close(p[1]);
    execlp("sort", "sort", "-r", (char *)0);
    wait(0);
    return EXIT_SUCCESS;
}