#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void testGetPID() {
    pid_t pid = getpid();
    pid_t ppid = getppid();  // pid_t 本质是有符号整数
    while (1) {
        printf("I am a precess, my ID is %d, my parent ID is %d\n", pid, ppid);
        sleep(1);
    }
}
void test2() {
    printf("before: only one line\n");
    fork();
    printf("after: only one line\n");
    sleep(1);
}

int main() {
    printf("begin:我是一个进程, pid: %d, ppid: %d\n", getpid(), getppid());
    pid_t id = fork();
    if (id == 0) {  // 子进程分支
        while (1) {
            printf("我是子进程, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    } else if (id > 0) {  // 父进程分支 成功时，子进程的PID > 0  返回到父进程
        while (1) {
            printf("我是父进程, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    } else {
        // error
    }
    return 0;
}
