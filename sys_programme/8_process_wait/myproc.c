#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10

// 非阻塞等待
void runChild() {
    int cnt = 5;
    while (cnt) {
        printf("I am child Process, pid: %d, ppid: %d\n", getpid(), getppid());
        cnt--;
        sleep(1);
    }
}
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed\n");
        return 1;
    } else if (pid == 0) {
        // child
        int cnt = 5;
        while (cnt) {
            printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
            cnt--;
            sleep(1);
        }
        exit(11);
    } else {
        int status = 0;
        while (1) {  // 轮询
            pid_t ret = waitpid(pid, &status, WNOHANG);
            // 等待成功或失败，退出轮询
            if (ret > 0) {
                // 等待成功，获取子进程退出信息
                if (WIFEXITED(status))
                    printf("子进程正常运行完毕，退出码 %d\n", WEXITSTATUS(status));
                else {
                    printf("进程退出异常\n");
                }
                break;
            } else if (ret < 0) {
                // 等待失败
                printf("wait failed\n");
                break;
            } else {
                // ret == 0
                printf("请问你运行完毕了吗？ 子进程还没有退出，再等等\n");
                sleep(1);
            }
        }
    }
    return 22;
}

// // waitpid 等待多个子进程
// void runChild() {
//     int cnt = 5;
//     while (cnt) {
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
//             exit(i);
//         }
//         // 父进程只会在循环内不断地创建子进程
//         printf("creat child process: %d success\n", id);  // 这行代码只有父进程会执行
//     }

//     for (int i = 0; i < N; ++i) {
//         int status = 0;
//         // 等待任意一个子进程
//         pid_t id = waitpid(-1, &status, 0);
//         if (id > 0) {
//             printf("wait %d success, exit code: %d\n", id, WEXITSTATUS(status));
//         }
//     }
//     sleep(3);
//     return 0;
// }

// // 7. 使用宏函数判断进程是否正常退出  并获取进程的退出码
// int main() {
//     pid_t pid = fork();
//     if (pid < 0) {
//         perror("fork failed\n");
//         return 1;
//     } else if (pid == 0) {
//         // child
//         int cnt = 3;
//         while (cnt) {
//             printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         exit(11);
//     } else {
//         // father
//         int cnt = 5;
//         while (cnt) {
//             printf("I am father, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         // 5 秒后 父进程对子进程进行wait回收
//         int status = 0;
//         pid_t ret = waitpid(pid, &status, 0);
//         if (ret == pid) {
//             // printf("wait success %d, exit sig: %d, exit code: %d\n", ret, status & 0x7F, (status >> 8) & 0xFF);
//             if (WIFEXITED(status))
//                 printf("进程正常执行完毕， 退出码: %d\n", WEXITSTATUS(status));
//             else {
//                 printf("进程出异常了\n");
//             }
//         } else {
//             printf("wait fail\n");
//         }
//         sleep(3);
//     }
//     return 0;
// }

// // 6. 进程等待的失败的场景
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
//         exit(1);
//     } else {
//         // father
//         int cnt = 10;
//         while (cnt) {
//             printf("I am father, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         // 10 秒后 父进程对子进程进行wait回收
//         int status = 0;
//         pid_t ret = waitpid(pid + 4, &status, 0);
//         if (ret == pid) {
//             printf("wait success %d, exit sig: %d, exit code: %d\n", ret, status & 0x7F, (status >> 8) & 0xFF);
//         } else {
//             printf("wait fail\n");
//         }
//         sleep(3);
//     }
//     return 0;
// }

// // 5. 获取子进程的退出状态
// int main() {
//     pid_t pid = fork();
//     if (pid < 0) {
//         perror("fork failed\n");
//         return 1;
//     } else if (pid == 0) {
//         // child
//         int cnt = 5;
//         while (1) {
//             printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         exit(1);
//     } else {
//         // father
//         int cnt = 10;
//         while (cnt) {
//             printf("I am father, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//             cnt--;
//             sleep(1);
//         }
//         // 10 秒后 父进程对子进程进行wait回收
//         int status = 0;
//         pid_t ret = waitpid(pid, &status, 0);
//         if (ret == pid) {
//             printf("wait success %d, exit sig: %d, exit code: %d\n", ret, status & 0x7F, (status >> 8) & 0xFF);
//         }
//         sleep(3);
//     }
//     return 0;
// }

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