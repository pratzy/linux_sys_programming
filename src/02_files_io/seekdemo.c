#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct
{
  int id;
  char name[80];
} record;

int main()
{
  const char *fname = "foo";
  int fd;
  size_t size_rec = sizeof(record);

  record rec = {
      .id = 10,
      .name = "John Smith"};

  printf("Size of record is %lu\n", size_rec);

  if ((fd = open(fname, O_WRONLY | O_TRUNC | O_CREAT, 0644)) < 0)
  {
    printf("Could not open file to write\n");
    perror(fname);
    exit(1);
  }

  if ((write(fd, &rec, sizeof(rec))) < 0)
  {
    printf("Could not write the record to file %s\n", fname);
    perror(fname);
    exit(1);
  }
  printf("Wrote record to file %s\n", fname);
  close(fd);

  // Let's try to read the record into another struct.
  record read_rec;
  if ((fd = open(fname, O_RDWR)) < 0)
  {
    printf("Could not open file to read\n");
    perror(fname);
    exit(1);
  }
  if (read(fd, &read_rec, size_rec) < 0)
  {
    printf("Could not read from file\n");
    exit(1);
  }
  printf("Record read..printing..\n");
  printf("id=%d\nname=%s\n", read_rec.id, read_rec.name);

  //Now let's modify this record and change the name.
  strcpy(read_rec.name, "Prateek Agarwal");
  read_rec.id = 2020;
  lseek(fd, -size_rec, SEEK_CUR);

  printf("Writing the updated record to file.\n");
  if ((write(fd, &read_rec, size_rec)) < 0)
  {
    printf("Could not write the updated record to file %s\n", fname);
    perror(fname);
    exit(1);
  }
  printf("Wrote the updated record to file %s\n", fname);
  close(fd);
}