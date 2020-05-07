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

#define BSIZE 16384

int main()
{
  int fin, fout;
  char buf[BSIZE];
  int read_bytes; // how many bytes were read

  if ((fin = open("foo", O_RDONLY)) < 0)
  {
    perror("foo");
    exit(1);
  }

  if ((fout = open("bar", O_WRONLY | O_CREAT, 0644)) < 0)
  {
    perror("bar");
    exit(1);
  }

  while((read_bytes = read(fin, buf, BSIZE)) > 0)
  {
    write(fout, buf, read_bytes);
  }

  close(fout);
  close(fin);

}