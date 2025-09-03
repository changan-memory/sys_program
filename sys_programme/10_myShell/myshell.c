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

char* argv[ARGC_SIZE];  // 存储命令解析后的多个字符串

const char* getUserName() {
    return getenv("USER");
}

const char* getHostName() {
    return getenv("HOSTNAME");
}

const char* getPwd() {
    return getenv("PWD");
}

void interact(char* cLine, int size) {
    if (strcmp("root", getUserName()) == 0)
        printf("%s@hcss-ecs-dfa9:%s" LABEL_ROOT " ", getUserName(), getPwd());
    else
        printf("%s@hcss-ecs-dfa9:%s" LABEL_USER " ", getUserName(), getPwd());

    char* s = fgets(cLine, size, stdin);
    assert(s);  // 就算直接输入回车，也输入了一个换行符，因此s一定不为空
    (void) s;   // 为了防止编译器对定义了但未使用的变量提示警告，我们这里使用以下 s

    // 输入命令时，会将字符串 最后键入的回车也读入，我们不想读入回车
    // strlen(commandLine) - 1  最小值为 0
    cLine[strlen(cLine) - 1] = '\0';  // 读入的字符串为 "xxxx\n\0"，将\n改为字符串的结束标记\0即可
}

int splitString(char* cLine, char* _argv[]) {
    int i = 0;
    _argv[i++] = strtok(cLine, DELIM);
    while (_argv[i++] = strtok(NULL, DELIM))  // 接着从上次的位置继续分割
        ;                                     // 一行代码完成字符串的分割，并且将argv中的最后一个参数置为NULL
    return i - 1;
}

void nomalExecute(char* _argv[]) {
    pid_t id = fork();
    if (id < 0) {
        perror("fork failed\n");
        return;
    } else if (id == 0) {
        // 子进程执行指令
        // execvpe(argv[0], argv, environ);
        execvp(_argv[0], _argv);
        // 程序替换有可能失败  exec 没有成功返回值，只有失败返回值
        exit(EXIT_CODE);
    } else {
        // 父进程等待
        int status = 0;                          // 获取子进程的退出状态
        pid_t retPid = waitpid(id, &status, 0);  // 等待子进程，传入status 阻塞等待
        if (retPid == id) {
            // 等待成功的处理逻辑
            lastCode = WEXITSTATUS(status);
        }
    }
}
// enum innerCommand {

// };
int main() {
    // 1. 初始化问题

    // 2. 交互问题
    while (!quit) {
        interact(commandLine, sizeof(commandLine));
        printf("echo: %s\n", commandLine);

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
        // 执行内建命令
        if (argc == 2 && strcmp(argv[0], "cd"))

            // 5. 执行普通指令
            nomalExecute(argv);
    }

    return 0;
}