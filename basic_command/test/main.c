// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// #define BODY '='
// #define HEAD '>'
// #define NUM 102
// #define TOP 100

// char bar[NUM] = {'\0'};
// const char* label = "|/-\\";

// int main() {
//     int len = strlen(label);
//     int cnt = 0;
//     while (cnt <= TOP) {
//         printf("[%-100s][%d%%][%c]\r", bar, cnt, label[cnt % 5]);
//         fflush(stdout);
//         bar[cnt] = BODY;
//         ++cnt;
//         if (cnt < TOP)
//             bar[cnt] = '>';
//         usleep(200000);
//     }
//     printf("\n");
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <unistd.h>

//缓冲区长度（含终止符）
#define NUM 102   // 102 表示字符数组的长度 0-100 101个字符  末尾是\0, 因此大小是 102
#define BODY '='  // 进度条主体字符
#define HEAD '>'  // 进度头部指示符
#define TOP 100   // 进度最大值

extern void progressbar(int speed);  // extern 声明外部变量时必须加上  函数声明可加可不加

char bar[NUM] = {0};
const char* label = "|/-\\";
void progressbar(int speed) {
    memset(bar, '\0', sizeof(bar));  //整体将字符串设为\0,可以方便的输出
    int len = strlen(label);

    int cnt = 0;
    while (cnt <= TOP) {
        //没有\n 就没有立即刷新，因为显示器默认是行刷新
        printf("[%-100s][%d%%][%c]\r", bar, cnt, label[cnt % len]);
        //预留出100空间，100s 默认是右对齐，进度条是反的, 用-100s解决
        //用变长的字符串，循环覆盖输出，实现进度条光标移动的效果
        //给进度条跑  %%显示百分号
        fflush(stdout);
        bar[cnt++] = BODY;  //更改进度条的风格
        if (cnt < TOP)
            bar[cnt] = '>';
        // sleep(1);
        usleep(speed);  // 100000微秒，用usleep实现更快的跑完
    }
    printf("\n");  //防止命令行提示符影响效果
}

int main() {
    progressbar(50000);
    return 0;
}