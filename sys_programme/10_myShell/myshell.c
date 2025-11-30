#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define LEFT "["
#define RIGHT "]"
#define LABEL_ROOT "#"
#define LABEL_USER "$"

#define DELIM " \t"  // 分隔符加上tab

#define LINE_SIZE 1024

#define ARGC_SIZE 32  // 命令中字符的最大个数

#define EXIT_CODE 44  // 子进程替换时的 退出码

extern char** environ;

char commandLine[LINE_SIZE];
int quit = 0;
int lastCode = 0;

char pwd[LINE_SIZE];  // 存储当前路径

// export 环境变量的原理是
// putenv 只是把环境变量字符串的地址 填入到系统环境变量表中
// 我们的环境变量是放在   char commandLine[LINE_SIZE] 数组中的，和其他解析后的命令共用一块空间
// 输入其他命令时，会把之前保存的环境变量覆盖掉，因此要再单独存储一份环境变量

// 自定义环境变量表
char myenv[LINE_SIZE];  // 自己实现的 环境变量标

// 自定义本地变量表
char myVal[LINE_SIZE];  // 存储Shell本地变量

const char* getUserName()
{
    return getenv("USER");
}

const char* getHostName()
{
    return getenv("HOSTNAME");
}

void getPwd()
{
    getcwd(pwd, sizeof(pwd));
}

void interact(char* cLine, int size)
{
    getPwd();
    if (strcmp("root", getUserName()) == 0)
        printf("%s@hcss-ecs-dfa9:%s " LABEL_ROOT " ", getUserName(), pwd);
    else
        printf("%s@hcss-ecs-dfa9:%s " LABEL_USER " ", getUserName(), pwd);

    char* s = fgets(cLine, size, stdin);
    assert(s);  // 就算直接输入回车，也输入了一个换行符，因此s一定不为空
    (void) s;   // 为了防止编译器对定义了但未使用的变量提示警告，我们这里使用以下 s

    // 输入命令时，会将字符串 最后键入的回车也读入，我们不想读入回车
    // strlen(commandLine) - 1  最小值为 0
    cLine[strlen(cLine) - 1] = '\0';  // 读入的字符串为 "xxxx\n\0"，将\n改为字符串的结束标记\0即可
}

int splitString(char* cLine, char* _argv[])
{
    int i = 0;
    _argv[i++] = strtok(cLine, DELIM);
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

        // 程序替换有可能失败  exec 没有成功返回值，只有失败返回值
        execvp(_argv[0], _argv);

        // execvp 一旦执行成功，程序不会走到这里
        // 走到这里表示 execvp 执行失败
        perror("execvp");
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

int buildCommand(int _argc, char* _argv[])
{
    if (_argc == 2 && strcmp(_argv[0], "cd") == 0)
    {
        // 通过环境变量获取路径比较麻烦，我们可以通过系统调用获取当前路径
        chdir(_argv[1]);
        getPwd();                           // 刷新当前路径
        sprintf(getenv("PWD"), "%s", pwd);  // 将当前路径写入到环境变量
        return 1;
    }
    // 处理 export 命令
    else if (_argc == 2 && strcmp(_argv[0], "export") == 0)
    {
        strcpy(myenv, _argv[1]);
        putenv(myenv);
        return 1;
    }
    // 处理 echo 命令
    else if (_argc == 2 && strcmp(_argv[0], "echo") == 0)
    {
        // lastCode 保存了上个子进程退出时的退出码 可以让用户通过 echo $? 获取到
        if (strcmp(_argv[1], "$?") == 0)
        {
            printf("%d\n", lastCode);
            lastCode = 0;
        }
        // 取环境变量
        else if (*_argv[1] == '$')
        {
            printf("%s\n", getenv(_argv[1] + 1));
        }
        //向终端输出文本
        else
        {
            // 自己学习一下 如何去掉引号
            printf("%s\n", _argv[1]);
        }
        return 1;
    }
    // 给ls加颜色
    if (strcmp(_argv[0], "ls") == 0)
    {
        _argv[_argc++] = "--color";
        _argv[_argc] = NULL;
    }
    return 0;
}
int main()
{
    char* argv[ARGC_SIZE];  // 存储命令解析后的多个字符串

    // 2. 交互问题
    while (!quit)
    {
        interact(commandLine, sizeof(commandLine));
        // printf("echo: %s\n", commandLine);

        // 3. 子串切割问题，解析命令行
        // commandLine 已经取到命令了，接下来对字符串做解析切割
        // commandLine "ls -a -l -b\n\0" ->  "ls" "-a" "-l"   解析后的字符串应该存起来
        int argc = splitString(commandLine, argv);
        if (argc == 0)
            continue;  // 什么都不输入时，继续等待舒服进行命令行解析

        // debug
        // for (int i = 0; argv[i]; i++)
        //     printf("%d: %s\n", i, argv[i]);

        // 4. 指令的判断  指令分为 普通命令和内建命令

        // 执行内建命令 内建命令  本质就是 Shell 内部的一个函数
        int n = buildCommand(argc, argv);

        // 5. 执行普通指令
        if (!n)
            nomalExecute(argv);
    }

    return 0;
}