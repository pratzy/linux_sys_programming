#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define FILE_NAME "foo"

typedef struct
{
    int id;
    char name[80];
} Record;

void print_records(Record *records, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Record %d : id=%d\tname=%s\n", i, records[i].id, records[i].name);
    }
}

void read_all_records(int fd)
{
    size_t file_size = lseek(fd, 0, SEEK_END);
    Record *records = (Record *)mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    print_records(records, 2);
    munmap(records, 2);
}

int main()
{
    int fd;
    size_t file_size;
    size_t record_size = sizeof(Record);

    fd = open(FILE_NAME, O_RDWR | O_TRUNC | O_CREAT);

    Record record = {
        .id = 10,
        .name = "Prateek"};
    write(fd, &record, record_size);
    printf("Record written\n");

    record.id = 20;
    strcpy(record.name, "John Doe");

    write(fd, &record, record_size);
    printf("Another record written\n");

    file_size = lseek(fd, 0, SEEK_END);

    Record *records = (Record *)mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    records[0].id = 99;
    strcpy(records[1].name, "John Smith");

    printf("Printing records BEFORE synching to mmap...\n");
    print_records(records, 2);

    if (msync(records, file_size, MS_SYNC) < 0)
    {
        fprintf(stderr, "Could not sync changes to file.!");
        perror("msync");
    }
    printf("Records updated via mmap.\n");

    printf("Printing records AFTER synching to mmap...\n");
    read_all_records(fd);

    munmap(records, 2);
    close(fd);
    return EXIT_SUCCESS;
}