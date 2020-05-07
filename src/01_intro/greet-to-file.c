#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
  int fd;
  if (( fd = open("foo", O_WRONLY | O_CREAT, 0644)) < 0)  // Perform, Assign, Evaluate, all in one step
  {
      printf("error number %d\n", errno);
      perror("foo");
      exit(1);
  }
  write(fd, "hello world", 11);
  close(fd);

}