#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 验证孤儿进程和僵尸进程的模块
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // child
        int cnt = 500;
        while (cnt) {
            printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
            cnt--;
            sleep(1);
        }
        exit(0);
    } else {
        // father
        int cnt = 5;
        while (cnt--) {
            printf("I am father, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }

        // 父进程没有针对子进程干任何事情
    }
    return 0;
}

// 验证进程阻塞的模块
// int main() {
//     while (1) {
//         sleep(1);
//         printf("hello world\n");
//     }
//     // int a = 0;
//     // printf("Please Enter #:");
//     // scanf("%d", &a);
//     // printf("%d\n", a);

//     return 0;
// }
// #include <stdio.h>

// 验证进程R和S的模块
// int main() {

//     while1(1) {
//         //printf("hello Linux World\n");
//     }
//     return 0;
// }
