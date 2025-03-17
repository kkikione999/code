#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return -1;
    }
    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);
    while (1)
    {
        sleep(10);
    }

    close(fd);
    return 0;
}