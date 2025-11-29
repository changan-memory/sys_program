#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define LEFT "{"
#define RIGHT "}"
#define LABEL_ROOT "#"
#define LABEL_USER "$"

#define DELIM " \t"

#define LINE_SIZE 1024
#define SPILT_SIZE 512

#define EXIT_CODE 66

#define ARGC_SZIE 32

char commandLine[LINE_SIZE];

char* argv[ARGC_SZIE];

char spiltPath[SPILT_SIZE];

int lastCode = 0;

const char* getUserName()  // 获取用户名
{
    return getenv("USER");
}

const char* getPwd()  // 获取当前路径
{
    char* curPath = getenv("PWD");

    int len = strlen(curPath);
    int i = len - 1;
    while (i >= 0 && curPath[i] != '/')
        --i;
    // i 停在 倒数第一个 '/' 的位置
    strcpy(spiltPath, curPath + i + 1);
    return spiltPath;
}

void interate()
{
    if (strcmp("root", getUserName()) == 0)
        printf(LEFT "%s@hcss-ecs-dfa9:~%s" LABEL_ROOT RIGHT " ", getUserName(), getPwd());
    else
        printf(LEFT "%s@hcss-ecs-dfa9:~%s" LABEL_USER RIGHT " ", getUserName(), getPwd());

    // scanf("%s", commandLine);
    char* s = fgets(commandLine, sizeof(commandLine), stdin);

    // 输入命令时，会将字符串 最后键入的回车也读入，我们不想读入回车
    // strlen(commandLine) - 1  最小值为 0
    commandLine[strlen(commandLine) - 1] = '\0';  // 读入的字符串为 "xxxx\n\0"，将\n改为字符串的结束标记\0即可

    // 以下三行为 debug
    assert(s);
    (void) s;
    // printf("%s", s);  // 我们手动将回车处理掉了
}

int splitString(char* cLine, char* _argv[])
{
    int i = 0;
    // _argv[i++] = strtok(cLine, DELIM);
    _argv[i++] = strtok(commandLine, DELIM);

    while (_argv[i++] = strtok(NULL, DELIM))  // 接着从上次的位置继续分割
        ;                                     // 一行代码完成字符串的分割，并且将argv中的最后一个参数置为NULL
    return i - 1;
}

void nomalExecute(char* _argv[])
{
    pid_t id = fork();
    if (id < 0)
    {
        perror("fork failed\n");
        return;
    }
    else if (id == 0)
    {
        // 子进程执行指令
        // execvpe(argv[0], argv, environ);

        execvp(_argv[0], _argv);
        // 程序替换有可能失败  exec 没有成功返回值，只有失败返回值
        exit(EXIT_CODE);
    }
    else
    {
        // 父进程等待
        int status = 0;                          // 获取子进程的退出状态
        pid_t retPid = waitpid(id, &status, 0);  // 等待子进程，传入status 阻塞等待
        if (retPid == id)
        {
            // 等待成功的处理逻辑
            lastCode = WEXITSTATUS(status);
        }
    }
}

int main()
{
    int quit = 0;
    while (!quit)
    {
        // 1. 交互
        interate();

        // 2. 命令行解析
        // 读取字符串后，对命令行做解析，切割
        // ls -a -l -> "ls" "-a" "-l"
        int argc = splitString(commandLine, argv);
        if (argc == 0)
            continue;

        // 3. 优先判断是否是内建命令

        // 4. 执行普通命令
        nomalExecute(argv);

        // debug
        for (int i = 0; argv[i]; ++i)
        {
            printf("[%d]-> : %s\n", i, argv[i]);
        }
    }
    return 0;
}