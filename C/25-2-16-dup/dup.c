#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644); // 打开文件
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int newfd = dup(fd); // 复制文件描述符
    if (newfd == -1) {
        perror("dup");
        return 1;
    }

    // 使用 newfd 来操作文件
    write(newfd, "Hello, World!\n", 14); // 使用复制的文件描述符写入文件
    
    close(fd);
    close(newfd);
    return 0;
}
