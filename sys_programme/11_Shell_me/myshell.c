// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// #define LEFT "{"
// #define RIGHT "}"
// #define LABEL_ROOT "#"
// #define LABEL_USER "$"

// #define DELIM " \t"

// #define LINE_SIZE 1024
// #define SPILT_SIZE 512

// #define EXIT_CODE 66

// #define ARGC_SZIE 32

// char commandLine[LINE_SIZE];

// char* argv[ARGC_SZIE];

// char spiltPath[SPILT_SIZE];

// int lastCode = 0;

// const char* getUserName()  // 获取用户名
// {
//     return getenv("USER");
// }

// const char* getPwd()  // 获取当前路径
// {
//     char* curPath = getenv("PWD");

//     int len = strlen(curPath);
//     int i = len - 1;
//     while (i >= 0 && curPath[i] != '/')
//         --i;
//     // i 停在 倒数第一个 '/' 的位置
//     strcpy(spiltPath, curPath + i + 1);
//     return spiltPath;
// }

// void interate()
// {
//     if (strcmp("root", getUserName()) == 0)
//         printf(LEFT "%s@hcss-ecs-dfa9:~%s" LABEL_ROOT RIGHT " ", getUserName(), getPwd());
//     else
//         printf(LEFT "%s@hcss-ecs-dfa9:~%s" LABEL_USER RIGHT " ", getUserName(), getPwd());

//     // scanf("%s", commandLine);
//     char* s = fgets(commandLine, sizeof(commandLine), stdin);

//     // 输入命令时，会将字符串 最后键入的回车也读入，我们不想读入回车
//     // strlen(commandLine) - 1  最小值为 0
//     commandLine[strlen(commandLine) - 1] = '\0';  // 读入的字符串为 "xxxx\n\0"，将\n改为字符串的结束标记\0即可

//     // 以下三行为 debug
//     assert(s);
//     (void) s;
//     // printf("%s", s);  // 我们手动将回车处理掉了
// }

// int splitString(char* cLine, char* _argv[])
// {
//     int i = 0;
//     // _argv[i++] = strtok(cLine, DELIM);
//     _argv[i++] = strtok(commandLine, DELIM);

//     while (_argv[i++] = strtok(NULL, DELIM))  // 接着从上次的位置继续分割
//         ;                                     // 一行代码完成字符串的分割，并且将argv中的最后一个参数置为NULL
//     return i - 1;
// }

// void nomalExecute(char* _argv[])
// {
//     pid_t id = fork();
//     if (id < 0)
//     {
//         perror("fork failed\n");
//         return;
//     }
//     else if (id == 0)
//     {
//         // 子进程执行指令
//         // execvpe(argv[0], argv, environ);

//         execvp(_argv[0], _argv);
//         // 程序替换有可能失败  exec 没有成功返回值，只有失败返回值
//         exit(EXIT_CODE);
//     }
//     else
//     {
//         // 父进程等待
//         int status = 0;                          // 获取子进程的退出状态
//         pid_t retPid = waitpid(id, &status, 0);  // 等待子进程，传入status 阻塞等待
//         if (retPid == id)
//         {
//             // 等待成功的处理逻辑
//             lastCode = WEXITSTATUS(status);
//         }
//     }
// }

// int main()
// {
//     int quit = 0;
//     while (!quit)
//     {
//         // 1. 交互
//         interate();

//         // 2. 命令行解析
//         // 读取字符串后，对命令行做解析，切割
//         // ls -a -l -> "ls" "-a" "-l"
//         int argc = splitString(commandLine, argv);
//         if (argc == 0)
//             continue;

//         // 3. 优先判断是否是内建命令

//         // 4. 执行普通命令
//         nomalExecute(argv);

//         // debug
//         for (int i = 0; argv[i]; ++i)
//         {
//             printf("[%d]-> : %s\n", i, argv[i]);
//         }
//     }
//     return 0;
// }

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

#define LINE_SIZE 1024

#define ARGC_SIZE 32

#define DELIM " \t"

#define EXIT_CODE 16

int quit = 0;
int lastCode = 0;

char commandLine[LINE_SIZE];  // 存储读入的命令

const char* getUserName()
{
    return getenv("USER");
}

const char* getHostName()
{
    return getenv("HOSTNAME");
}

const char* getPwd()
{
    return getenv("PWD");
}

char spiltPath[512];

const char* setPwd()  // 获取当前路径
{
    char* curPath = getenv("PWD");

    // /home/userName
    // 将/home/userName/ 替换为 ~/
    int i = 6;
    while (i < strlen(curPath) && curPath[i] != '/')
        ++i;
    // i 停在 用户名后的第一个 '/' 的位置
    strcpy(spiltPath, curPath + i);
    return spiltPath;
}

void interact(char* cLine, int size)
{
    if (strcmp(getUserName(), "root") == 0)
        printf(LEFT "%s@hcss-ecs-dfa9:~%s" RIGHT LABEL_ROOT, getUserName(), setPwd());
    else
        printf(LEFT "%s@hcss-ecs-dfa9:~%s" RIGHT LABEL_USER, getUserName(), setPwd());

    char* str = fgets(cLine, size, stdin);
    assert(str);  // 即使直接输入回车，也有一个字符，因此str不可能为空

    // 下标 strlen(commandLine) 指向的为 '\0'，再减一定位到 末尾的换行符
    cLine[strlen(cLine) - 1] = '\0';

    // 验证结果，看读入的字符串是否正确
    // printf("%s", str);
}

// int splitString(char* cLine, char* _argv[])
// {
//     int i = 0;
//     _argv[i++] = strtok(cLine, DELIM);
//     while (_argv[i++] = strtok(NULL, DELIM))
//         ;
//     return i - 1;
// }

int splitString(char* cLine, char* _argv[], int _max_args)
{
    if (_max_args <= 0)
        return 0;

    int i = 0;
    char* tok = strtok(cLine, DELIM);
    while (tok != NULL && i < _max_args - 1)  // 最后一个位置要置 NULL
    {
        _argv[i++] = tok;
        tok = strtok(NULL, DELIM);
    }
    // 如果还有剩余 token 但超出 _argv 容量，应该决定如何处理（这里忽略多余的 token）
    _argv[i] = NULL;  // 保证以 NULL 结尾
    return i;         // 返回实际的 token 个数
}

void nomalExecute(char* argv[])
{
    pid_t id = fork();
    if (id < 0)
    {
        perror("fork failed\n");
        return;  // 当shell fork 子进程失败时，代表shell 以及挂了，因此直接 return
    }
    // 子进程 进程程序替换，执行命令
    else if (id == 0)
    {
        // 程序替换有可能失败  exec 没有成功返回值，只有失败返回值
        execvp(argv[0], argv);

        // execvp 一旦执行成功，程序不会走到这里
        // 走到这里表示 execvp 执行失败
        perror("execvp");
        exit(EXIT_CODE);
    }
    // 父进程 等待子进程完成任务
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
    char* argv[ARGC_SIZE];
    // shell 本质是一个死循环

    while (!quit)
    {
        // 1. 输出命令行提示符号进行交互，并读取输入的命令字符串
        interact(commandLine, sizeof(commandLine));

        // 2. 对输入的命令进行命令行解析，，拆分为 指令名 + 选项
        int argc = splitString(commandLine, argv, ARGC_SIZE);

        // 3. 判断输入的指令是否有效，无效时什么都不做
        if (argc == 0)
            continue;
        // 验证解析出来的字符串
        for (int i = 0; argv[i]; ++i)
            printf("[%d]->: %s\n", i, argv[i]);

        // 4. 判断是否是内建命令，内建命令调用Shell 内部的函数执行

        // 5. 非内建命令，fork 出子进程, 执行命令
        nomalExecute(argv);
    }
    return 0;
}