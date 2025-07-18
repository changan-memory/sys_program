#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // child
        int cnt = 500;
        while (cnt) {
            printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
            cnt--;
            sleep(1);
        }
        exit(0);
    } else {
        // father
        int cnt = 5;
        while (cnt--) {
            printf("I am father, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }

        // 父进程没有针对子进程干任何事情
    }
    return 0;
}

// int main() {
//     while (1) {
//         sleep(1);
//         printf("hello world\n");
//     }
//     // int a = 0;
//     // printf("Please Enter #:");
//     // scanf("%d", &a);
//     // printf("%d\n", a);

//     return 0;
// }
