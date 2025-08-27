#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10

// 5. 获取子进程的退出状态
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed\n");
        return 1;
    } else if (pid == 0) {
        // child
        int cnt = 5;
        while (1) {
            printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
            cnt--;
            sleep(1);
        }
        exit(1);
    } else {
        // father
        int cnt = 10;
        while (cnt) {
            printf("I am father, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
            cnt--;
            sleep(1);
        }
        // 10 秒后 父进程对子进程进行wait回收
        int status = 0;
        pid_t ret = waitpid(pid, &status, 0);
        if (ret == pid) {
            printf("wait success %d, exit sig: %d, exit code: %d\n", ret, status & 0x7F, (status >> 8) & 0xFF);
        }
        sleep(3);
    }
    return 0;
}

// 4. 演示waitpid()的用法
// int main() {
//     pid_t pid = fork();
//     if (pid < 0) {
//         perror("fork failed\n");
//         return 1;
//     } else if (pid == 0) {
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
//         int cnt = 10;
//         while (cnt) {
//             printf("I am father, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         // 10 秒后 父进程对子进程进行wait回收
//         // wait 是等待任意一个子进程退出
//         // pid_t ret = wait(NULL);  // 暂时传入 NULL 指针，不关心子进程的状态
//         pid_t ret = waitpid(-1, NULL, 0);
//         if (ret == pid) {
//             printf("wait success %d\n", ret);
//         }
//         sleep(5);
//     }
//     return 0;
// }

// // wait 等待多个子进程，但任意一个子进程永不退出的场景
// void runChild() {
//     int cnt = 5;
//     while (1) {
//         printf("I am child Process, pid: %d, ppid: %d\n", getpid(), getppid());
//         cnt--;
//         sleep(1);
//     }
// }
// int main() {
//     for (int i = 0; i < N; ++i) {
//         pid_t id = fork();
//         if (id == 0) {
//             runChild();
//             exit(0);
//         }
//         // 父进程只会在循环内不断地创建子进程
//         printf("creat child process: %d success\n", id);  // 这行代码只有父进程会执行
//     }
//     // sleep(10);

//     // wait 一次只能等待任意一个子进程，如何等待多个进程
//     // 等待多个进程时，任意一个子进程都不退出
//     for (int i = 0; i < N; ++i) {
//         pid_t id = wait(NULL);
//         if (id > 0) {
//             printf("wait %d success\n", id);
//         }
//     }
//     sleep(5);
//     return 0;
// }

// // wait 多个子进程的场景
// void runChild() {
//     int cnt = 5;
//     while (cnt) {
//         printf("I am child Process, pid: %d, ppid: %d\n", getpid(), getppid());
//         cnt--;
//         sleep(1);
//     }
// }
// // 2. 如果有多个子进程，wait如何正确等待
// int main() {
//     for (int i = 0; i < N; ++i) {
//         pid_t id = fork();
//         if (id == 0) {
//             runChild();
//             exit(0);
//         }
//         // 父进程只会在循环内不断地创建子进程
//         printf("creat child process: %d success\n", id);  // 这行代码只有父进程会执行
//     }
//     sleep(10);

// // wait 一次只能等待任意一个子进程，如何等待多个进程
// for (int i = 0; i < N; ++i) {
//     pid_t id = wait(NULL);
//     if (id > 0) {
//         printf("wait %d success\n", id);
//     }
// }
//     sleep(5);
//     return 0;
// }

// 1. wait 的基本使用
// int main() {
//     pid_t pid = fork();
//     if (pid < 0) {
//         perror("fork failed\n");
//         return 1;
//     } else if (pid == 0) {
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
//         int cnt = 10;
//         while (cnt) {
//             printf("I am father, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         // 10 秒后 父进程对子进程进行wait回收
//         // wait 是等待任意一个子进程退出
//         pid_t ret = wait(NULL);  // 暂时传入 NULL 指针，不关心子进程的状态
//         if (ret == pid) {
//             printf("wait success %d\n", ret);
//         }
//         sleep(5);
//     }
//     return 0;
// }