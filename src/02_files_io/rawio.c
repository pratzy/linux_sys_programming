#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FILENAME "rawio.out"

int main(int argc, char *argv[])
{
    char *buffer;
    int fd, block_size, block_count;

    if (argc != 3)
    {
        printf("usage: %s <blocksize> <blockcount>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    block_size = atoi(argv[1]);
    block_count = atoi(argv[2]);

    if ((buffer = malloc(block_size)) == NULL)
        fprintf(stderr, "Error creating buffer with size %d", block_size);

    for (int i = 0; i < block_count; i++)
    {
        write(fd, buffer, block_size);
    }

    free(buffer);
    buffer = NULL;

    close(fd);
    return EXIT_SUCCESS;
}