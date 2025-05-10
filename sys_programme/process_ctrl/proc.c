#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    while (1) {
        printf("I am a precess, my ID is %d, my parent ID is %d\n", pid, ppid);
        sleep(1);
    }
    return 0;
}
