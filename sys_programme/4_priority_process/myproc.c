#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 验证进程优先级的模块
int main() {
    while (1) {
        printf("I am a process, pid: %d\n", getpid());
        sleep(1);
    }
    return 0;
}
