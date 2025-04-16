#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
using namespace std;

void test1() {
    // read only
    // 此处是相对于build目录的路径l
    int fd = open("../a.c", O_RDONLY | O_CREAT | O_TRUNC, 0777);
    // 0644    rw-r--r--
    // errno 是错误编号  strerror(errno) 可以翻译错误编号
    if (fd == -1)
        cout << strerror(errno) << endl;
    else
        cout << "File descriptor: " << fd << endl;
}
int main(int argc, char** argv) {
    test1();

    return 0;
}
