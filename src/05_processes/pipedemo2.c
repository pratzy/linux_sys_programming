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
        // Child 1 - Upstream (Producer)
        // Connect stdout to pipe
        dup2(p[1], 1);
        close(p[0]);
        execlp("ls", "ls", (char *)0);
    }
    if (fork() == 0)
    {
        // Child 2 - Downstream (Consumer)
        // Connect stdin to pipe
        dup2(p[0], 0);
        close(p[1]);
        execlp("sort", "sort", "-r", (char *)0);
    }
    close(p[0]);
    close(p[1]);

    wait(0);
    wait(0);
    return EXIT_SUCCESS;
}