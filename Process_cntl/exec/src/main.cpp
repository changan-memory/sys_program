#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <iostream>

int main(int argc, char** argv) {
    using namespace std;
    pid_t pid = fork();
    if (pid == -1) {
        exit(1);
    } else if (pid == 0) {
        // cout << "i am child process" << endl;
        // execlp("ls", "-l", "-d", "-h", NULL);  错误写法 NULL作为哨兵
        // -d 是查看目录，导致出现的结果比较少
        // execlp("ls", "ls", "-l", "-h", "-a", NULL);  // 结尾需要加上 NULL作为哨兵
        execlp("date", "date", NULL);  // 结尾需要加上 NULL作为哨兵
        cerr << "execlp error" << endl;
        exit(1);
    } else {
        cout << " I am parent process" << endl;
    }

    return 0;
}
