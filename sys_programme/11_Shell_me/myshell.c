#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LEFT "["
#define RIGHT "]"

const char* getUserName() {
    return getenv("USER");
}
const char* getPwd() {
    return getenv("PWD");
}

int main() {
    char hostName[256] = {'\0'};
    if (1)
        return 0;
}