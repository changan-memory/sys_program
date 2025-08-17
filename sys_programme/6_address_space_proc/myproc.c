#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// int g_val = 100;
// int main() {
//     pid_t id = fork();
//     if (id == 0) {
//         //子进程
//         int cnt = 5;
//         while (1) {
//             printf("i am child, pid: %d, ppid: %d, g_val = %d, &g_val = %p\n", getpid(), getppid(), g_val, &g_val);
//             sleep(1);
//             if (cnt)
//                 cnt--;
//             else {
//                 g_val = 200;
//                 printf("子进程 change g_val: 100->200\n");
//                 cnt--;
//             }
//         }
//     } else {
//         //父进程
//         while (1) {
//             printf("i am parent, pid: %d, ppid: %d, g_val = %d, &g_val = %p\n", getpid(), getppid(), g_val, &g_val);
//             sleep(1);
//         }
//     }
//     return 0;
// }

int g_val_1;        // 未初始化全局变量
int g_val_2 = 100;  // 已初始化全局变量
int main() {
    printf("code addr: %p\n", main);
    const char* str = "hello world";  // 字符串常量
    printf("read only string addr: %p\n", str);
    printf("init global value addr: %p\n", &g_val_2);    // 已初始化全局变量
    printf("uninit global value addr: %p\n", &g_val_1);  // 未初始化全局变量
    static int static_int = 100;
    printf("static local value addr: %p\n", &static_int);  // static 修饰的局部变量 存储在全局数据区

    char* mem = (char*) malloc(100);   // 堆区的数据
    char* mem1 = (char*) malloc(100);  // 堆区的数据
    char* mem2 = (char*) malloc(100);  // 堆区的数据
    printf("heap addr: %p\n", mem);    // 打印堆区地址
    printf("heap addr: %p\n", mem1);   // 打印堆区地址
    printf("heap addr: %p\n", mem2);   // 打印堆区地址
    return 0;
}

// void test(int n) {
//     int local_var = n;  // 每层递归都会有一个新的局部变量
//     printf("递归深度 %2d, 局部变量地址: %p\n", n, &local_var);

//     if (n > 0) {
//         test(n - 1);  // 继续递归
//     }
// }

// int main() {
//     test(10);  // 从 10 层开始递归
//     return 0;
// }

// int main() {
//     char* str = "hello world";
//     *str = 'H';
//     return 0;
// }
