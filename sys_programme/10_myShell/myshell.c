#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT "["
#define RIGHT "]"
#define LABEL_ROOT "#"
#define LABEL_USER "$"

#define LINE_SIZE 1024

const char* getUserName() {
    return getenv("USER");
}

const char* getHostName() {
    return getenv("HOSTNAME");
}

const char* getPwd() {
    return getenv("PWD");
}

void interact(char* commandLine, int size) {
    if (strcmp("root", getUserName()) == 0)
        printf("%s@hcss-ecs-dfa9:%s" LABEL_ROOT " ", getUserName(), getPwd());
    else
        printf("%s@hcss-ecs-dfa9:%s" LABEL_USER " ", getUserName(), getPwd());

    char* s = fgets(commandLine, size, stdin);
    assert(s);  // 就算直接输入回车，也输入了一个换行符，因此s一定不为空
    (void) s;   // 为了防止编译器对定义了但未使用的变量提示警告，我们这里使用以下 s

    // 输入命令时，会将字符串 最后键入的回车也读入，我们不想读入回车
    // strlen(commandLine) - 1  最小值为 0
    commandLine[strlen(commandLine) - 1] = '\0';  // 读入的字符串为 "xxxx\n\0"，将\n改为字符串的结束标记\0即可
}
int main() {
    char commandLine[LINE_SIZE];
    int quit = 0;
    while (!quit) {
        interact(commandLine, sizeof(commandLine));
        printf("echo: %s\n", commandLine);
        // commandLine 已经取到命令了，接下来对字符串做解析
    }

    return 0;
}