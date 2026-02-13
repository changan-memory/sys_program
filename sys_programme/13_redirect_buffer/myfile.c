#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define fileName "log.txt"

// 标准输出1标准错误2有什么区别
int main()
{
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");

    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");

    return 0;
}

// // dup2 输出重定向
// // 这个代码与缓冲区有关
// int main()
// {
//     int fd = open(fileName, O_CREAT | O_WRONLY | O_APPEND, 0666);

//     if (fd < 0)
//     {
//         perror("open fail");
//         return 1;
//     }
//     dup2(fd, 1);
//     close(fd);

//     printf("fd: %d\n", fd);
//     printf("hello printf\n");
//     fprintf(stdout, "hello fprintf\n");

//     close(fd);
//     return 0;
// }

// // dup2 输入重定向
// int main()
// {
//     int fd = open(fileName, O_RDONLY, 0666);

//     if (fd < 0)
//     {
//         perror("open fail");
//         return 1;
//     }

//     // 输入重定向，本来是从标准输入键盘读 现在是从文件读
//     dup2(fd, 0);

//     char buffer[1024];
//     ssize_t s = read(0, buffer, sizeof(buffer) - 1);
//     if (s > 0)
//     {
//         buffer[s] = '\0';
//         printf("echo#: %s\n", buffer);
//     }

//     close(fd);
//     return 0;
// }

// // dup2 输出重定向
// int main()
// {
//     int fd = open(fileName, O_CREAT | O_WRONLY | O_APPEND, 0666);

//     // int fd = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     if (fd < 0)
//     {
//         perror("open fail");
//         return 1;
//     }

//     dup2(fd, 1);
//     close(fd);

//     const char* message = "hello Linux\n";
//     int cnt = 5;
//     while (cnt)
//     {
//         write(1, message, strlen(message));
//         cnt--;
//     }

//     close(fd);
//     return 0;
// }

// 文件的重定向
// int main()
// {
//     close(1);
//     int fd = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     if (fd < 0)
//     {
//         perror("open fail");
//         return 1;
//     }

//     const char* message = "hello Linux\n";
//     int cnt = 5;
//     while (cnt)
//     {
//         write(1, message, strlen(message));
//         cnt--;
//     }

//     close(fd);
//     return 0;
// }

// 文件描述符的分配规则
// int main()
// {
//     // close(0);
//     // close(1);
//     close(2);
//     int fd = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     if (fd < 0)
//     {
//         perror("open fail");
//         return 1;
//     }

//     printf("fd = %d\n", fd);
//     const char* message = "hello Linux\n";
//     int cnt = 5;
//     while (cnt)
//     {
//         write(fd, message, strlen(message));
//         cnt--;
//     }

//     close(fd);
//     return 0;
// }

