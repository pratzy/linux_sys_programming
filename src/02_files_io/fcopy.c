/*
 Lowest level IO

 Command to generate data to 'foo' file:
 dd if=/dev/urandom of=foo bs=1000 count=1000
 
 This write 1000 random bytes to foo
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define BUFSIZE 16384

int main(int argc, char **argv)
{
    FILE *fin, *fout;
    char *file_in = "foo";
    char *file_out = "bar";
    char *buf[BUFSIZE];
    size_t read_bytes;

    if ((fin = fopen(file_in, "r")) < 0)
    {
        printf("Cannot open file for reading.\n");
        perror(file_in);
    }
    if ((fout = fopen(file_out, "w")) < 0)
    {
        printf("Cannot open file for writing\n");
        perror(file_out);
    }

    while ((read_bytes = fread(buf, 1, BUFSIZE, fin)) > 0)
        fwrite(buf, 1, read_bytes, fout);

    fclose(fin);
    fclose(fout);
}