#include "lseek.h"

void LSeek::GetSize_lseek()
{
    int fd = open("../resource/lseek.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        exit(1);
    }
    // char string[] = "I am a lseek test";
    // // 读和写用的是同一个地址
    // write(fd, string, strlen(string));

    int sz = lseek(fd, 0, SEEK_END); // 写入之后把光标移到 开头
    cout << "大小为 " << sz << endl;
    close(fd);
}

void LSeek::ExpandSize_truncate()
{
    int ret = truncate("../resource/lseek.txt", 250);
    cout << ret << endl;
}

void LSeek::ExpandSize_lseek()
{
    int fd = open("../resource/lseek.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
        exit(1);
    }
    int sz = lseek(fd, 111, SEEK_END); // 从文件末尾偏移 111 个字节
    cout << "大小为 " << sz << endl;
    write(fd, "6", 1);
    cout << "大小为 " << sz << endl;
    close(fd);
}