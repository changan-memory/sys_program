#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// 在父子进程中分别打印 自己的 pid 号 和 父进程的 Pid 号
void test1()
{
    cout << "before fork--1---------------" << endl;
    cout << "before fork--2---------------" << endl;
    cout << "before fork--3---------------" << endl;
    cout << "before fork--4---------------" << endl;
    cout << "before fork--5---------------" << endl;
    pid_t pid = fork();
    // fork之后的代码  父子进程都有   会被执行两遍
    if (pid == -1)
    {
        perror("fork error");
        exit(0);
    }
    else if (pid == 0)
    {
        cout << "child process is created" << endl;
        cout << "My pid is " << getpid() << endl;
        cout << "My parent pid is " << getppid() << endl;
    }
    else if (pid > 0)
    {
        cout << "this is parent, my child is " << pid << endl;
        cout << "my pid is " << getpid() << " my parent pid is " << getppid() << endl;
    }

    cout << "================end of file" << endl
         << endl;
}

// 循环创建 n 个子进程
void test2()
{
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();
        // fork之后的代码  父子进程都有   会被执行两遍
        if (pid == -1)
        {
            perror("fork error");
            exit(0);
        }
        else if (pid == 0)
        {
            cout << "child process is created" << endl;
            cout << "My pid is " << getpid() << endl;
            cout << "My parent pid is " << getppid() << endl;
        }
        else if (pid > 0)
        {
            cout << "this is parent, my child is " << pid << endl;
            cout << "my pid is " << getpid() << " my parent pid is " << getppid() << endl;
        }

        cout << "================end of file" << endl;
    }
}
int main(int argc, char **argv)
{
    // test1();
    // test2();
    int n = 3;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (fork() == 0)
            break;
    }
    if (i == 3)
        cout << "I am parent" << endl;
    else
    {
        // sleep(1);
        cout << "I am " << i + 1 << "th child" << endl;
    }

    return 0;
}
