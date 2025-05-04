#include <unistd.h>

// progressbar(20000);
//模拟调用进度条
// int total = 1000, curr = 0;     //目前curr需要从0开始
// while(curr <= total){
//     progressbar(curr * 100 / total);
//     //模拟正在进行某种下载任务
//     curr += 10;
//     usleep(50000);
//     //printf("\n");        //防止命令行提示符影响效果
// }
// printf("\n");        //防止命令行提示符影响效果

#include "progressBar.h"

void test() {
    // printf("hello world\n");  验证缓冲区的存在
    // printf("hello world");

    //实现一个倒计时
    int cnt = 100;
    while (cnt >= 0) {
        // printf("%-2d\r", cnt);//使用\r回车会导致三位数只刷新了两位数
        printf("%-3d\r", cnt);  // %3d\r可以实现在行的开头更新数字  -相当于反转  确保是左对齐
        fflush(stdout);
        cnt--;
        sleep(1);
    }
    printf("\n");
}

//通过任务调用进度条
//外部程序通过回调，调用进度条
// void (*callback_t)(int) , callback_t是函数指针 typedef void (*)(int) callback_t  把callback_t变成函数指针类型
// typedef void (*callback_t)(int);
void downLoad(callback_t cb) {
    //模拟调用进度条
    int total = 1000;
    int curr = 0;  //目前curr需要从0开始
    while (curr <= total) {
        //进行某种下载任务
        usleep(50000);
        int rate = curr * 100 / total;

        cb(rate);  //回调展示进度
        curr += 10;
    }
    printf("\n");  //防止命令行提示符影响效果
}
int main() {
    // // test();
    printf("downLoan 1:\n");
    downLoad(progressbar);
    initBar();
    printf("downLoan 2:\n");
    downLoad(progressbar);
    initBar();
    printf("downLoan 3:\n");
    downLoad(progressbar);
    initBar();
    return 0;
}
