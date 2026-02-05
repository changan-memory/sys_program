#include <stdio.h>
#include <string.h>
#include <unistd.h>

// int main()
// {
//     // chdir("/home/changan_memory");
//     // printf("PID: %d\n", getpid());

//     // 打开文件的路径和文件名，默认在当前路径下新建一个文件
//     FILE* fp = fopen("log.txt", "w");  // 以 w 方式打开文件是，该文件不存在时，会自动创建
//     if (fp == NULL)
//     {
//         perror("fopen fail\n");
//         return 1;
//     }
//     const char* message = "hello Linux message";

//     fwrite(message, strlen(message), 1, fp);

//     fclose(fp);

//     // sleep(100);
//     return 0;
// }

// int main()
// {
//     // 打开文件的路径和文件名，默认在当前路径下新建一个文件
//     FILE* fp = fopen("log.txt", "w");  // 以 w 方式打开文件是，该文件不存在时，会自动创建
//     if (fp == NULL)
//     {
//         perror("fopen fail\n");
//         return 1;
//     }
//     // const char* message = "hello Linux message";
//     const char* message = "abcde";
//     // 写入时是否要将 '\0' 写入? strlen(message) 是否要+1
//     // 字符串以 '\0' 结尾, 是C语言的规定, 和文件无关. 写入时只需要将字符串的内容写入即可
//     fwrite(message, strlen(message), 1, fp);

//     fclose(fp);

//     // sleep(100);
//     return 0;
// }

// int main()
// {
//     // 打开文件的路径和文件名，默认在当前路径下新建一个文件
//     FILE* fp = fopen("log.txt", "w");  // 以 w 方式打开文件是，该文件不存在时，会自动创建
//     if (fp == NULL)
//     {
//         perror("fopen fail\n");
//         return 1;
//     }

//     fclose(fp);

//     return 0;
// }

// int main()
// {
//     // 打开文件的路径和文件名，默认在当前路径下新建一个文件
//     FILE* fp = fopen("log.txt", "a");  // 以 w 方式打开文件是，该文件不存在时，会自动创建
//     if (fp == NULL)
//     {
//         perror("fopen fail\n");
//         return 1;
//     }
//     // const char* message = "hello Linux message";
//     const char* message = "abcde";

//     // 向默认打开的文件流去写入
//     // 对C语言来说，向显示器打印内容，和向文件中写入内容，没有区别
//     // fwrite(message, strlen(message), 1, stdout);
//     fprintf(fp, "%s: %d\n", message, 1234);

//     fclose(fp);

//     // sleep(100);
//     return 0;
// }

// 测试代码
// 系统调用级别的文件操作
#define ONE (1 << 0)    // 1
#define TWO (1 << 1)    // 2
#define FOUR (1 << 2)   // 4
#define EIGHT (1 << 3)  // 8

void show(int flags)
{
    if (flags & ONE)
        printf("hello function1: %d\n", (flags & ONE));
    if (flags & TWO)
        printf("hello function2: %d\n", (flags & TWO));
    if (flags & FOUR)
        printf("hello function4: %d\n", (flags & FOUR));
    if (flags & EIGHT)
        printf("hello function8 : %d\n", (flags & EIGHT));
}

int main()
{
    printf("-----------------------------\n");
    show(ONE);
    printf("-----------------------------\n");
    show(TWO);
    printf("-----------------------------\n");

    show(ONE | TWO);
    printf("-----------------------------\n");
    show(ONE | TWO | FOUR);
    printf("-----------------------------\n");
    show(ONE | FOUR);
    printf("-----------------------------\n");
    show(FOUR | EIGHT);
    printf("-----------------------------\n");
}
