#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
using namespace std;

#include "lseek.h"

void test() {
    LSeek lseek;
    // lseek.ExpandSize_lseek();
    lseek.GetSize_lseek();
    // lseek.ExpandSize_truncate();
}
int main(int argc, char* argv[]) {
    int fd = open("../resource/lseek.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }
    char string[] = "I am a lseek test";

    // 读和写用的是同一个地址
    write(fd, string, strlen(string));
    lseek(fd, 0, SEEK_SET);  // 写入之后把光标移到 开头

    int n = 0;
    char ch;
    while (n = read(fd, &ch, 1)) {
        if (n < 0) {
            perror("read lseek.txt error");
            exit(1);
        }
        write(STDOUT_FILENO, &ch, n);  // 读多少 写多少
    }
    // test();
    return 0;
}
