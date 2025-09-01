#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "otherExe begin running" << endl;
    for (int i = 0; argv[i]; ++i) {
        cout << i << " : " << argv[i] << endl;
    }
    cout << "otherExe stop running" << endl;

    return 0;
}