#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 环境变量，可以让程序获取到当前系统中的用户是谁
// int main() {
//     // int i = 0;
//     // for (; i < 10; ++i) {
//     //     printf("hello %d\n", i);
//     // }
//     char who[32];
//     strcpy(who, getenv("USER"));
//     if (strcmp(who, "root") == 0) {
//         printf("你是root用户, 可以做任何事情\n");
//     } else {
//         printf("你是普通用户, 受到权限约束\n");
//     }
//     return 0;
// }

// C/C++ 程序 两张表  main函数的第三个参数
// 1. 命令行参数 向量表  2. 环境变量 向量表   这两张表的结构一模一样
// int main(int argc, char* argv[], char* env[]) {
//     // 遍历argv的另一种方式
//     int i = 0;
//     // argv 和 env 的最后一个元素存储的是NULL，遍历到结尾时，条件自动为假，所以退出循环
//     for (; env[i]; ++i) {
//         // printf("argv[%d]->%s\n", i, env[i]);
//         printf("%s\n", env[i]);
//     }
//     return 0;
// }

// 通过C语言提供的 外部变量 environ 获取环境变量
int main() {
    int i = 0;
    extern char** environ;
    // argv 和 env 的最后一个元素存储的是NULL，遍历到结尾时，条件自动为假，所以退出循环
    for (; environ[i]; ++i) {
        // printf("argv[%d]->%s\n", i, env[i]);
        printf("%s\n", environ[i]);
    }
    return 0;
}

// // 遍历 argv的另一种方式
// int main(int argc, char* argv[]) {
//     // 遍历argv的另一种方式
//     int i = 0;
//     // argv的最后一个元素存储的是NULL，遍历到结尾时，条件自动为假，所以退出循环
//     for (; argv[i]; ++i) {
//         printf("argv[%d]->%s\n", i, argv[i]);
//     }
//     return 0;
// }

// int main(int argc, char* argv[]) {
//     // argc 是一个整数, argv是一个字符串数组
//     // argv字符串数组的大小 由 argv 决定
//     // int i = 0;
//     // for (; i < argc; ++i) {
//     //     printf("argv[%d]->%s\n", i, argv[i]);
//     // }

//     if (argc != 2) {
//         printf("Useag: %s -[a|b|c|d]\n", argv[0]);
//         return 0;
//     }
//     if (strcmp(argv[1], "--help") == 0) {
//         printf("Useag: %s -[a|b|c|d]\n", argv[0]);
//     } else if (strcmp(argv[1], "-a") == 0) {
//         printf("功能1\n");
//     } else if (strcmp(argv[1], "-b") == 0) {
//         printf("功能2\n");
//     } else if (strcmp(argv[1], "-c") == 0) {
//         printf("功能3\n");
//     } else if (strcmp(argv[1], "-d") == 0) {
//         printf("功能4\n");
//     } else {
//         printf("default功能\n");
//     }
//     return 0;
// }