#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
using namespace std;
#include <dirent.h>

void Myls(const char* path) {
    DIR* dp = opendir(path);
    if (dp == NULL) {
        cerr << "opendir error" << endl;
        exit(1);
    }
    struct dirent* sdir;

    while ((sdir = readdir(dp)) != NULL) {
        // cout << readdir(dp)->d_name << endl;
        if (strcmp(sdir->d_name, ".") == 0 || strcmp(sdir->d_name, "..") == 0)
            continue;
        cout << sdir->d_name << endl;
        //  printf("%s\n", sdir->d_name);
    }
    closedir(dp);
}

int main(int argc, char* argv[]) {
    Myls(argv[1]);
    return 0;
}
