#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("dup2.txt", O_RDWR | O_CREAT, 0644); // 打开文件
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int newfd = 10; // 自定义一个新的文件描述符
    if (dup2(fd, 1) == -1) { // 复制到新的文件描述符
        perror("dup2");
        return 1;
    }

    printf("!!!!!!!!!!!!!!!!!!!!!!!!\n");
    close(fd);
    close(newfd);
    return 0;
}
