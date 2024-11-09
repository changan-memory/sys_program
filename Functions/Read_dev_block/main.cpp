#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void read_write_v1()
{
    char buf[10];
    int n = 0;
    n = read(STDIN_FILENO, buf, 10); // 从标准输入读
    // int flags = fcntl(STDIN_FILENO, F_GETFL);
    // flags |= O_NONBLOCK;
    // int ret = fcntl(STDIN_FILENO, F_SETFL, flags);
    if (n < 0)
    {
        perror("read SRDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);
}

void read_write_v2()
{
    char buf[10];
    int n = 0;
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
tryagain:
    n = read(fd, buf, 10);
    if (fd < 0)
    {
        if (errno != EAGAIN)
        {
            perror("read /dev/tty");
            exit(1);
        }
        else
        {
            write(STDOUT_FILENO, "try again\n", strlen("try again\n"));
            sleep(5);
            goto tryagain;
        }
    }

    write(fd, buf, n);
    close(fd);
}
int main(int argc, char **argv)
{
    // read_write_v1();
    // read_write_v2();
    char buf[10];
    int n = 0;
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    // cout << "11111" << endl;
    if (fd < 0)
    {
        perror("open /dev/tty");
        exit(1);
    }
    cout << "open /dev/tty ok ... " << fd << endl;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        n = read(fd, buf, 10);
        if (n > 0) // 说明读到了东西
            break;
        // n 不大于 0
        if (errno != EAGAIN)
        {
            // 说明是 以非阻塞方式读终端  并且终端中没有数据
            perror("read /dev/tty");
            exit(1);
        }
        else
        { //
            write(STDOUT_FILENO, "try again\n", strlen("try again\n"));
            sleep(3);
        }
    }
    if (i == 5)
        write(STDOUT_FILENO, "time out\n", strlen("time out\n"));
    else
        write(STDOUT_FILENO, buf, n);
    close(fd);
    return 0;
}
