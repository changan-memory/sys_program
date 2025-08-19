#include <errno.h>
#include <stdio.h>
#include <stdlib.h>  // exit(0) 这个用法需要这个头文件
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// 8 进程退出 exit

void show() {
    printf("hello show 1\n");
    printf("hello show 2\n");
    printf("hello show 3\n");
    printf("hello show 4\n");
    // exit(13);
    return;
}
int main() {
    show();
    printf("hello Linux\n");
    return 12;
}

// // 7 confirm
// int main() {
//     while (1) {
//         printf("hello Linux: pid: %d\n", getpid());
//         sleep(1);
//     }
//     return 0;
// }

// 6 出异常的场景
// int main() {
//     // int a = 10;
//     // a /= 0;
//     int* p = NULL;
//     *p = 10;
//     return 0;
// }

//// 5
// int main() {
//     int ret = 0;
//     char* p = (char*) malloc(1000 * 1000 * 1000 * 4);
//     if (p == NULL) {
//         // 这么写，既能知道错误码，还能知道错误信息
//         printf("malloc error: %d, %s\n", errno, strerror(errno));
//         ret = errno;  // 还能将错误码转换成进程的退出码，让父进程也知道出错了
//     } else {
//         // 使用内存的逻辑
//         printf("malloc success\n");
//     }
//     return ret;
// }

// // 4
// int main() {
//     int ret = 0;
//     char* p = (char*) malloc(1000 * 1000 * 1000 * 4);
//     if (p == NULL) {
//         printf("malloc error\n";
//         ret = 1;
//     } else {
//         // 使用内存的逻辑
//         printf("malloc success\n");
//     }
//     return ret;
// }

// // 3
// int main() {
//     // 查看不同的退出码对应的错误信息
//     for (int i = 0; i < 150; ++i) {
//         printf("%d: %s\n", i, strerror(i));
//     }
//     return 0;  // 进程的退出码 表征进程的运行结果是否正确 0->success
// }

// 2
// int main() {
//     printf("模拟一个逻辑的实现\n");
//     return 11;
// }

// 1
// #define N 5

// void runChild() {
//     int cnt = 10;
//     while (cnt--) {
//         printf("I am child: pid: %d, ppid: %d\n", getpid(), getppid());
//         sleep(1);
//     }
// }
// // 如何创建 5个子进程
// int main() {
//     for (int i = 0; i < N; ++i) {
//         pid_t id = fork();
//         if (id == 0) {
//             // 子进程
//             runChild();
//             exit(0);  // 父进程没有等待，退出后，子进程会变成僵尸进程
//         }
//         // if 之后是父进程，什么都没做，接着执行循环
//     }
//     // 父进程等待 1000秒
//     sleep(1000);
//     return 0;
// }