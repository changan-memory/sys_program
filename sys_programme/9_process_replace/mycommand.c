#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());

    // 这类方法的标准写法 方便记忆
    // 最后一个参数必须是 NULL , 第一个参数是可执行文件的路径
    execl("/usr/bin/ls", "ls", "-a", "-l", NULL);

    printf("after: I am a process pid: %d, ppid: %d\n", getpid(), getppid());

    return 0;
}