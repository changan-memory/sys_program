#include "progressBar.h"

#include <string.h>
#include <unistd.h>

// v2 应用
//  char bar[NUM] = {0};
char bar[NUM] = {0};
const char* label = "|/-\\";
void initBar() {
    memset(bar, '\0', sizeof(bar));
}

void progressbar(int rate) {
    if (rate < 0 || rate > 100)
        return;

    int len = strlen(label);

    ////没有\n 就没有立即刷新，因为显示器默认是行刷新预留出100s空间，100s 默认是右对齐，进度条是  反 的, 用-100s解决
    //用单个字符循环覆盖输出实现光标闪动
    printf("[%-100s][%d%%][%c]\r", bar, rate, label[rate % len]);

    //给进度条跑  %%显示百分号
    fflush(stdout);
    bar[rate++] = BODY;  //更改进度条的风格
    if (rate < TOP)
        bar[rate] = HEAD;
    // printf("\n");        //防止命令行提示符影响效果
}

// v1  原理
// void progressbar(int speed) {
//     // printf("hello test Bar\n");
//     char bar[NUM];
//     memset(bar, '\0', sizeof(bar));  //整体设为\0,可以方便的输出
//     int len = strlen(label);

//     int cnt = 0;
//     while (cnt <= TOP) {
//         //没有\n 就没有立即刷新，因为显示器默认是行刷新
//         printf("[%-100s][%d%%][%c]\r", bar, cnt, label[cnt % len]);
//         //预留出100空间，100s 默认是右对齐，进度条是反的, 用-100s解决
//         //用变长的字符串，循环覆盖输出，实现进度条光标移动的效果
//         //给进度条跑  %%显示百分号
//         fflush(stdout);
//         bar[cnt++] = BODY;  //更改进度条的风格
//         if (cnt < TOP)
//             bar[cnt] = '>';
//         // sleep(1);
//         usleep(speed);  // 100000微秒，用usleep实现更快的跑完
//     }
//     printf("\n");  //防止命令行提示符影响效果
// }
