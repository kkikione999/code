#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd , len;

    if (argc < 3)
    {
        printf("Usage: %s <file> <string>\n", argv[0]);
        return -1;
    }
    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    printf("argc = %d\n", argc);
    printf("argv[1] = %s\n", argv[1]);
    printf("argv[2] = %s\n", argv[2]);
    printf("sizeof(argv[2]) = %ld\n", sizeof(argv[2]));
    printf("len = %ld\n", strlen(argv[2]));
    len = strlen(argv[2]);

    write(fd,argv[2],len);
    write(fd,"\r\n",2);
    printf("fd = %d\n", fd);
    while (1)
    {
        sleep(10);
    }
    close(fd);
    return 0;
}