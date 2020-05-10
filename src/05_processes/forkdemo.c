#include <stdio.h>
#include <unistd.h>

int main()
{
    if (fork()) // fork() returns PID of the parent which will always be greater than 0
        printf("I am the parent\n");
    else
    {
        printf("I am the child\n");
    }
}