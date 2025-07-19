#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 模拟验证僵尸进程的模块
// 僵尸进程  子进程退出后，父进程没有对子进程的资源进行回收
// int main() {
//     pid_t pid = fork();
//     if (pid == 0) {
//         // child
//         int cnt = 5;
//         while (cnt) {
//             printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         exit(0);
//     } else {
//         // father
//         // int cnt = 5;
//         // while (cnt--) {
//         while (1) {
//             printf("I am father, pid: %d, ppid: %d\n", getpid(), getppid());
//             sleep(1);
//         }
//         // 父进程没有针对子进程干任何事情
//     }
//     return 0;
// }

// 模拟验证孤儿进程的模块
// 父进程先于子进程结束，子进程由系统的1号进程init进程接管
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
