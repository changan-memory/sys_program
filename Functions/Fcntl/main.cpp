#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define MSG_TRY "try again\n"

int main(int argc, char **argv)
{
    char buf[10];
    int flags, n;
    flags = fcntl(STDIN_FILENO, F_GETFL); // 获取终端文件的 状态   属性信息
    if (flags == -1)
    {
        perror("fcntl error");
        exit(1);
    }
    // 或等于  把位图(是一个整型)中 表示阻塞与否的那一位改成 1
    flags |= O_NONBLOCK; // 给状态数  加上非阻塞
    int ret = fcntl(STDOUT_FILENO, F_SETFL, flags);
    if (ret == -1)
    {
        perror("fcnt; error");
        exit(1);
    }
tryagain:
    n = read(STDIN_FILENO, buf, 10);
    if (n < 0)
    {
        if (errno != EAGAIN)
        {
            perror("read error");
            exit(1);
        }
        sleep(3);
        write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
        goto tryagain;
    }
    // n> 0
    write(STDOUT_FILENO, buf, n);

    return 0;
}
