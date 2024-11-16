#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
using namespace std;

void test1() {
    int fd, ret;
    char* p = "test of unlink\n";
    char* p2 = "after write something.\n";

    fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open temp error");
        exit(1);
    }
    // 写入两行
    ret = write(fd, p, strlen(p));
    if (ret == -1) {
        perror("-----write error");
    }

    printf("hi! I'm printf\n");
    ret = write(fd, p2, strlen(p2));
    if (ret == -1) {
        perror("-----write error");
    }

    printf("Enter anykey continue\n");
    getchar();

    ret = unlink("temp.txt");  // 具备了被释放的条件
    if (ret < 0) {
        perror("unlink error");
        exit(1);
    }

    close(fd);
}

void test2() {
    int fd, ret;
    char* p = "test of unlink\n";
    char* p2 = "after write something.\n";

    fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open temp error");
        exit(1);
    }
    // 写入两行
    ret = write(fd, p, strlen(p));
    if (ret == -1) {
        perror("-----write error");
    }

    printf("hi! I'm printf\n");
    ret = write(fd, p2, strlen(p2));
    if (ret == -1) {
        perror("-----write error");
    }

    p[3] = 'H';

    printf("Enter anykey continue\n");
    getchar();

    ret = unlink("temp.txt");  // 具备了被释放的条件
    if (ret < 0) {
        perror("unlink error");
        exit(1);
    }

    close(fd);
}
int main(int argc, char* argv[]) {
    int fd = 0;
    int ret = 0;
    char* p = "test of unlink\n";
    char* p2 = "after write something.\n";
    /*
    解决办法是检测fd有效性后，立即释放temp.txt，由于进程未结束，虽然temp.txt的硬链接数已经为0，但还不会立即释放，仍然存在，要等到程序执行完才会释放。这样就能避免程序出错导致临时文件保留下来。

    因为文件创建后，硬链接数立马减为0，即使程序异常退出，这个文件也会被清理掉。这时候的内容是写在内核空间的缓冲区。*/
    fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open temp error");
        exit(1);
    }
    ret = unlink("temp.txt");  // 具备了被释放的条件
    // 在发生错误之前就让  临时文件具备 被 释放的条件 从而保证   即使发生错误  临时文件也能被正确删除

    if (ret < 0) {
        perror("unlink error");
        exit(1);
    }
    // unlink 之后 write函数是 写在了内核的缓冲区
    ret = write(fd, p, strlen(p));
    if (ret == -1) {
        perror("-----write error");
    }

    printf("hi! I'm printf\n");
    ret = write(fd, p2, strlen(p2));
    if (ret == -1) {
        perror("-----write error");
    }

    printf("Enter anykey continue\n");
    getchar();

    p[3] = 'H';

    close(fd);
    return 0;
}
