#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define LEFT "{"  // 控制括号格式
#define RIGHT "}"
#define LABEL_ROOT "#"  // 控制不同用户的命令行提示符
#define LABEL_USER "$"
int quit = 0;  // 全局控制，控制命令行的退出状态

#define DELIM " \t"  // 分隔符加上tab

#define LINE_SIZE 1024

#define ARGC_SIZE 32  // 命令中字符的最大个数

#define EXIT_CODE 16  // 子进程替换时的 退出码

extern char** environ;

char commandLine[LINE_SIZE];  // 存储读入的命令

int lastCode = 0;

char pwd[LINE_SIZE];  // 存储当前路径

// export 环境变量的原理是
// putenv 只是把环境变量字符串的地址 填入到系统环境变量表中
// 我们的环境变量是放在   char commandLine[LINE_SIZE] 数组中的，和其他解析后的命令共用一块空间
// 输入其他命令时，会把之前保存的环境变量覆盖掉，因此要再单独存储一份环境变量

// 自定义环境变量表
char* myenv[LINE_SIZE];  // 全局变量，自动置为 NULL

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
    if (strcmp(getUserName(), "root") == 0)
        printf(LEFT "%s@hcss-ecs-dfa9:%s" RIGHT LABEL_ROOT, getUserName(), pwd);
    else
        printf(LEFT "%s@hcss-ecs-dfa9:%s" RIGHT LABEL_USER, getUserName(), pwd);

    char* str = fgets(cLine, size, stdin);
    assert(str);  // 即使直接输入回车，也有一个字符，因此str不可能为空
                  // 就算直接输入回车，也输入了一个换行符，因此str一定不为空

    // 输入命令时，会将字符串 最后键入的回车也读入，我们不想读入回车
    // 下标 strlen(commandLine) 指向的为 '\0'，再减一定位到 末尾的换行符     strlen(commandLine) - 1  最小值为 0
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

void nomalExecute(char* _argv[])
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
        execvp(_argv[0], _argv);

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

int buildExecute(int _argc, char* _argv[])
{
    // 处理内建命令 cd
    if (_argc <= 2 && strcmp(_argv[0], "cd") == 0)
    {
        if (_argc == 1)
            chdir(getenv("HOME"));
        else
            chdir(_argv[1]);

        // 通过环境变量获取路径比较麻烦，我们可以通过系统调用获取当前路径
        // chdir 后，当前路径确实改变了，但是环境变量表和命令行提示符中的路径没变，需要解决
        getPwd();  // 刷新当前路径
        // sprintf(getenv("PWD"), "%s", pwd);  // 将当前路径写入到环境变量
        setenv("PWD", pwd, 1);  // 将当前路径写入到环境变量

        return 1;
    }
    // 处理内建命令 export  并实现自定义环境变量表
    else if (_argc == 2 && strcmp(_argv[0], "export") == 0)
    {
        // putenv 只是把环境变量字符串的地址 填入到系统环境变量表中
        // 我们的环境变量是放在   char commandLine[LINE_SIZE] 命令行中的，和其他解析后的命令共用一块空间
        // 输入其他命令时，会把之前保存的环境变量覆盖掉，因此要再单独存储一份环境变量

        for (int i = 0; i < LINE_SIZE; ++i)
        {
            if (myenv[i] == NULL)
            {
                myenv[i] = (char*) malloc(strlen(_argv[1]) + 1);
                if (myenv[i] == NULL)
                {
                    perror("malloc fail");
                    return 1;
                }

                strcpy(myenv[i], _argv[1]);

                if (putenv(myenv[i]) != 0)
                    perror("putenv fail\n");

                break;
            }
        }

        return 1;
    }
    // 处理内建命令 echo
    else if (_argc == 2 && strcmp(_argv[0], "echo") == 0)
    {
        // echo $? 获取上次进程的退出码
        // lastCode 保存了上个子进程退出时的退出码 可以让用户通过 echo $？获取
        if (strcmp(_argv[1], "$?") == 0)
        {
            printf("%d\n", lastCode);
            lastCode = 0;
        }
        // echo 环境变量和本地变量的情况 echo $
        else if (_argv[1][0] == '$')
        {
            // echo getenv获取不存在的环境变量时，会返回NULL
            // 如果不检测，会发生段错误
            char* val = getenv(_argv[1] + 1);
            if (val)
                printf("%s\n", val);
        }
        // echo 原样输出字符串的情况
        else
        {
            char* s = _argv[1];
            int len = strlen(s);

            if (len >= 2 && s[0] == '"' && s[len - 1] == '"')
            {
                s[len - 1] = '\0';  // 去掉尾部引号
                s++;                // 跳过首部引号
            }

            printf("%s\n", s);

            // 以上是自己学习的去掉引号的方法
            // printf("%s\n", _argv[1]);
        }
        return 1;
    }

    // 单独给 ls 命令加颜色 无需 return 0
    if (strcmp(_argv[0], "ls") == 0)
    {
        _argv[_argc++] = "--color";
        _argv[_argc] = NULL;
    }
    // 不匹配内建命令就 return 0  去执行普通命令
    return 0;
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
    }
    return 0;
}