#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// int main()
// {
//     printf("stdin->fd: %d\n", stdin->_fileno);
//     printf("stdout->fd: %d\n", stdout->_fileno);
//     printf("stderr->fd: %d\n", stderr->_fileno);
//     return 0;
// }

int main()
{
    close(1);
    int res = printf("stdin->fd: %d\n", stdin->_fileno);
    printf("stdout->fd: %d\n", stdout->_fileno);
    printf("stderr->fd: %d\n", stderr->_fileno);

    fprintf(stderr, "%d\n", res);
    return 0;
}

// int main()
// {
//     char buf[1024];
//     ssize_t s = read(0, buf, sizeof(buf) - 1);
//     if (s < 0)
//         return 1;
//     buf[s] = '\0';

//     const char* message = "hello Linux\n";
//     write(1, message, strlen(message));
//     write(2, message, strlen(message));
//     printf("%s\n", buf);
//     return 0;
// }

// int main()
// {
//     umask(0);
//     int fd1 = open("log1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     int fd2 = open("log2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     int fd3 = open("log3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     int fd4 = open("log4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
//     {
//         perror("open file fail");
//     }
//     printf("fd1: %d\n", fd1);
//     printf("fd2: %d\n", fd2);
//     printf("fd3: %d\n", fd3);
//     printf("fd4: %d\n", fd4);

//     close(fd1);
//     close(fd2);
//     close(fd3);
//     close(fd4);
//     return 0;
// }

// int main()
// {
//     umask(0);
//     int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     // int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);

//     if (fd < 0)
//     {
//         perror("open file fail");
//     }

//     const char* message = "hello Linux";
//     write(fd, message, strlen(message));
//     close(fd);
//     return 0;
// }

// int main()
// {
//     // printf("stdin->fd: %d\n", stdin->_fileno);
//     // printf("stdout->fd: %d\n", stdout->_fileno);
//     // printf("stderr->fd: %d\n", stderr->_fileno);
//     const char* message = "hello Linux";
//     fprintf(stdout, "%s: %d\n", message, 1234);
//     printf("%s: %d\n", message, 1234);
//     fprintf(stderr, "%s: %d\n", message, 1234);
//     return 0;
// }

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
// 系统调用 常用的传参方式
// 可以用一个比特位来表示一个状态
// #define ONE (1 << 0)    // 1
// #define TWO (1 << 1)    // 2
// #define FOUR (1 << 2)   // 4
// #define EIGHT (1 << 3)  // 8

// void show(int flags)
// {
//     if (flags & ONE)
//         printf("hello function1: %d\n", (flags & ONE));
//     if (flags & TWO)
//         printf("hello function2: %d\n", (flags & TWO));
//     if (flags & FOUR)
//         printf("hello function4: %d\n", (flags & FOUR));
//     if (flags & EIGHT)
//         printf("hello function8 : %d\n", (flags & EIGHT));
// }

// int main()
// {
//     printf("-----------------------------\n");
//     show(ONE);
//     printf("-----------------------------\n");
//     show(TWO);
//     printf("-----------------------------\n");

//     show(ONE | TWO);
//     printf("-----------------------------\n");
//     show(ONE | TWO | FOUR);
//     printf("-----------------------------\n");
//     show(ONE | FOUR);
//     printf("-----------------------------\n");
//     show(FOUR | EIGHT);
//     printf("-----------------------------\n");
// }
