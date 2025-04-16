#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class LSeek
{
public:
    void GetSize_lseek();       // 获取文件大小
    void ExpandSize_lseek();    // 虚假的扩展文件大小
    void ExpandSize_truncate(); // 真正拓展文件大小
};