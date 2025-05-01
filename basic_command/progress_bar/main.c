#include <unistd.h>
#include "progressBar.h"

void test(){
    //printf("hello world\n");  验证缓冲区的存在
    //printf("hello world");
    
    //实现一个倒计时
    int cnt = 100;
    while(cnt >= 0){

        //printf("%-2d\r", cnt);//使用\r回车会导致三位数只刷新了两位数
        printf("%-3d\r", cnt);// %3d\r可以实现在行的开头更新数字  -相当于反转  确保是左对齐
        fflush(stdout);
        cnt--;
        sleep(1);
    }
    printf("\n");
}



int main(){   
    //progressbar(); 
    test();
    return 0;
}
