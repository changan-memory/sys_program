#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t id = 0;
    id = fork();
    if (id == -1) {
        printf("fork error\n");
    } else if (id == 0) {
        while (1) {
            printf("I am child process, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }

    } else if (id > 0) {
        while (1) {
            printf("I am father process, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    } else {
        ;
    }
    return 0;
}
