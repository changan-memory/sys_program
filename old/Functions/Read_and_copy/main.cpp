#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
using namespace std;

#define N 1024

int main(int argc, char** argv) {
    char buf[N];
    int n = 0;

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror("open error");  // 匹配错误符号和错误信息
        exit(1);               // 退出程序
    }
    int fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0777);

    if (fd2 == -1) {
        perror("open error");  // 匹配错误符号和错误信息
        exit(1);               // 退出程序
    }

    while ((n = read(fd1, buf, 1024)) != 0) {
        if (n < 0) {
            perror("read error");
            break;
        }
        int x = write(fd2, buf, n);
        if (x == -1) {
            perror("write error");
            break;
        }
    }
    close(fd1);
    close(fd2);

    return 0;
}
