#include <stdio.h>
#include <unistd.h>

int main()
{
    chdir("/home/changan_memory");
    printf("PID: %d\n", getpid());
    // 打开文件的路径和文件名，默认在当前路径下新建一个文件
    FILE* fp = fopen("log.txt", "w");  // 以 w 方式打开文件是，该文件不存在时，会自动创建
    if (fp == NULL)
    {
        perror("fopen fail\n");
        return 1;
    }
    fclose(fp);

    sleep(100);
    return 0;
}