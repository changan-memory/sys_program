#pragma once

#include <stdio.h>

#define NUM 102     //102 表示字符数组的长度 0-100 101个字符  末尾是\n, 因此大小是 102
#define BODY '='
#define HEAD '>'
#define TOP 100

typedef void (*callback_t)(int);    //函数指针类型 

extern void progressbar(int rate);  //extern 声明外部变量时必须加上  函数声明可加可不加
extern void downLoad(callback_t cb);
extern void initBar();
 

