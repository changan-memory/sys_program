#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// 通过使用验证各个exec系列函数的用法





// // 多进程 程序替换
// int main() {
//     pid_t id = fork();

//     if (id == 0) {
//         // child
//         printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         sleep(5);

//         // 这类方法的标准写法 方便记忆
//         // 最后一个参数必须是 NULL , 第一个参数是可执行文件的路径
//         execl("/usr/bin/ls", "ls", "-a", "-l", NULL);

//         printf("after: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         exit(0);
//     }
//     // father
//     pid_t ret = waitpid(id, NULL, 0);  // 等待子进程，暂不关心进程退出状态，阻塞等待
//     if (ret > 0) {
//         printf("wait success, father: %d, ret %d\n", getpid(), ret);
//         sleep(5);
//     }
//     return 0;
// }

// // 单进程 程序替换演示
// int main() {
//     printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());

//     // 这类方法的标准写法 方便记忆
//     // 最后一个参数必须是 NULL , 第一个参数是可执行文件的路径
//     execl("/usr/bin/ls", "ls", "-a", "-l", NULL);

//     printf("after: I am a process pid: %d, ppid: %d\n", getpid(), getppid());

//     return 0;
// }