#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BODY '='
#define HEAD '>'
#define NUM 102
#define TOP 100

char bar[NUM] = {'\0'};
const char* label = "|/-\\";

int main() {
    int len = strlen(label);
    int cnt = 0;
    while (cnt <= TOP) {
        printf("[%-100s][%d%%][%c]\r", bar, cnt, label[cnt % 5]);
        fflush(stdout);
        bar[cnt] = BODY;
        ++cnt;
        if (cnt < TOP)
            bar[cnt] = '>';
        usleep(200000);
    }
    printf("\n");
    return 0;
}