#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    link(argv[1], argv[2]);
    unlink(argv[1]);
    return 0;
}
