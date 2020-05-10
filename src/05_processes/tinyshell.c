#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char line[100];

    while(printf(">"), gets(line) != NULL)
    {
        if(fork() == 0)
        {
            execlp(line, line, (char *) 0);
        } else {
            wait(0);
        }
    }
}