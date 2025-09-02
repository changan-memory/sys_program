#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t id = fork();
    extern char** environ;
    if (id == 0) {
        // child
        printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
        sleep(3);

        // execle("./otherExe", "otherExe", "-a", "-b", NULL, environ);  // 传系统的环境变量

        // 传自定义的环境变量 会完全覆盖从系统继承下来的环境变量
        char* const myenv[] = {"MYVAL=123456", "MYPATH=/usr/bin/xxx", NULL};
        execle("./otherExe", "otherExe", "-a", "-b", NULL, myenv);

        printf("after: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
        exit(0);
    }
    // father
    pid_t ret = waitpid(id, NULL, 0);  // 等待子进程，暂不关心进程退出状态，阻塞等待
    if (ret > 0) {
        printf("wait success, father: %d, ret %d\n", getpid(), ret);
        sleep(3);
    }
    return 0;
}

// // 给子进程传新的环境变量
// // execle  使用自定义的环境变量
// int main() {
//     pid_t id = fork();
//     extern char** environ;
//     if (id == 0) {
//         // child
//         printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         sleep(3);

//         execle("./otherExe", "otherExe", "-a", "-b", NULL, environ);  // 传系统的环境变量

//         // 传自定义的环境变量
//         // char* const myenv[] = {"MYVAL=123456", "MYPATH=/usr/bin/xxx", NULL};
//         // execle("./otherExe", "otherExe", "-a", "-b", NULL, myenv);

//         printf("after: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         exit(0);
//     }
//     // father
//     pid_t ret = waitpid(id, NULL, 0);  // 等待子进程，暂不关心进程退出状态，阻塞等待
//     if (ret > 0) {
//         printf("wait success, father: %d, ret %d\n", getpid(), ret);
//         sleep(3);
//     }
//     return 0;
// }

// // 1. putenv 添加环境变量
// int main() {
//     pid_t id = fork();
//     putenv("MYPRIVATE_ENV=123456");
//     if (id == 0) {
//         // child
//         printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         sleep(3);

//         char* const myargv[] = {"otherExe", "-a", "-b", NULL};
//         execv("./otherExe", myargv);

//         printf("after: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         exit(0);
//     }
//     // father
//     pid_t ret = waitpid(id, NULL, 0);  // 等待子进程，暂不关心进程退出状态，阻塞等待
//     if (ret > 0) {
//         printf("wait success, father: %d, ret %d\n", getpid(), ret);
//         sleep(3);
//     }
//     return 0;
// }

// // 验证不同程序间 命令行参数和环境变量
// int main() {
//     pid_t id = fork();

//     if (id == 0) {
//         // child
//         printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         sleep(3);

//         char* const myargv[] = {"otherExe", "-a", "-b", NULL};
//         execv("./otherExe", myargv);

//         printf("after: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         exit(0);
//     }
//     // father
//     pid_t ret = waitpid(id, NULL, 0);  // 等待子进程，暂不关心进程退出状态，阻塞等待
//     if (ret > 0) {
//         printf("wait success, father: %d, ret %d\n", getpid(), ret);
//         sleep(3);
//     }
//     return 0;
// }

// // 通过使用验证各个exec系列函数的用法
// int main() {
//     pid_t id = fork();

//     if (id == 0) {
//         // child
//         printf("before: I am a process pid: %d, ppid: %d\n", getpid(), getppid());
//         sleep(5);

//         // execl("/usr/bin/ls", "ls", "-a", "-l", NULL);
//         // execlp("ls", "ls", "-a", "-l", NULL);

//         // execv 的用法
//         // char* const myargv[] = {"ls", "-a", "-l", NULL};
//         // execv("/usr/bin/ls", myargv);

//         // // execvp 的用法
//         // char* const myargv[] = {"ls", "-a", "-l", NULL};
//         // execvp("ls", myargv);

//         // // 执行我们自己写的程序  用C语言程序 调用C++程序
//         // execl("./otherExe", "otherExe", NULL);

//         // // C语言程序调用 shell 脚本
//         // execl("/usr/bin/bash", "bash", "test.sh", NULL);

//         // C语言程序调用 python 脚本
//         execl("/usr/bin/python3", "python3", "test.py", NULL);

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