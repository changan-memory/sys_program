#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
using namespace std;

// 利用 link 和 unlink 实现 mv 命令
int main(int argc, char* argv[]) {
    // 将源文件链接 到新的路径   再删除原来的路径
    link(argv[1], argv[2]);
    unlink(argv[1]);
    return 0;
}
