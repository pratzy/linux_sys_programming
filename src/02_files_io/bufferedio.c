#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FILENAME "bufferedio.out"

int main(int argc, char *argv[])
{
    char *buffer;
    FILE *fd;
    int block_size, block_count;

    if (argc != 3)
    {
        printf("usage: %s <blocksize> <blockcount>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = fopen(FILENAME, "w");

    block_size = atoi(argv[1]);
    block_count = atoi(argv[2]);

    if ((buffer = malloc(block_size)) == NULL)
        fprintf(stderr, "Error creating buffer with size %d", block_size);

    for (int i = 0; i < block_count; i++)
    {
        fwrite(buffer, block_size, 1, fd);
    }

    free(buffer);
    buffer = NULL;

    fclose(fd);
    return EXIT_SUCCESS;
}