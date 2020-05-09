#include <sys/uio.h>
#include <string.h>
#include <stdio.h>

#define STDOUT 1

int main()
{
  static char part2[] = "This is from writev!";
  static char part1[] = "[";
  static char part3[] = "]\n";
  struct iovec iov[3];
  
  iov[0].iov_base = part1;
  iov[0].iov_len = strlen(part1);

  iov[1].iov_base = part2;
  iov[1].iov_len = strlen(part2);

  iov[2].iov_base = part3;
  iov[2].iov_len = strlen(part3);

  size_t iov_len = sizeof(iov)/sizeof(struct iovec);
  printf("Size of iov: %lu\n", iov_len);
  writev(STDOUT, iov, iov_len);

  return 0;
}