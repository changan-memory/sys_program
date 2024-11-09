#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sys/stat.h>
using namespace std;

int main(int argc, char *argv[])
{
    struct stat ptr_buf;
    // int ret = stat(argv[1], &ptr_buf);
    int ret = lstat(argv[1], &ptr_buf);
    if (ret == -1)
    {
        perror("stat error");
        exit(1);
    }
    cout << ptr_buf.st_size << endl;
    if (S_ISREG(ptr_buf.st_mode))
    {
        cout << "regular" << endl;
    }
    else if (S_ISDIR(ptr_buf.st_mode))
    {
        cout << "dir file" << endl;
    }
    else if (S_ISLNK(ptr_buf.st_mode))
    {
        cout << "soft links" << endl;
    }
    else if (S_ISFIFO(ptr_buf.st_mode))
        cout << "is a pipe" << endl; // 管道文件

    return 0;
}
