#include <iostream>
using namespace std;

//#include "Math_lib.h"
#include "Cal_lib.h"

int main(int argc, char **argv)
{

    int val1 = 10;
    int val2 = 20;
    std::cout << "before swap " << val1 << " " << val2 << std::endl;

    swap(val1, val2);

    std::cout << "\nafter swap " << val1 << " " << val2 << std::endl;

    cout << Add(val1, val2) << endl;
    cout << Sub(val1, val2) << endl;
    cout << Mul(val1, val2) << endl;
    cout << Div(val1, val2) << endl;

    print();
}