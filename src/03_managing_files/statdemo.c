#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct stat buf;

    stat("foo", &buf);

    printf("last accessed: %s", ctime(&buf.st_atime));
    printf("last modified: %s", ctime(&buf.st_mtime));
    printf("last changed: %s", ctime(&buf.st_ctime));
    return EXIT_SUCCESS;
}