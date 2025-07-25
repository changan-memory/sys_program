//  验证g++下的迭代器失效问题
#include <iostream>
#include <vector>
using namespace std;

void test1() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    auto it = v.begin();
}

int main() {
    cout << "删除所有的偶数： " << endl;
    // 删除所有的偶数
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);  // 加上该行后，erase会出错
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);  // 加上该行后会出现段错误
    cout << "before erase: ";
    for (auto& e : v)
        cout << e << " ";
    cout << endl;
    auto it = v.begin();
    while (it != v.end()) {
        if (*it % 2 == 0) {
            v.erase(it);
        }
        //把 ++it 放在else逻辑中后，两个问题全部解决了
        else {
            ++it;
        }
        // ++it;
    }
    cout << "after erase: ";
    for (auto& e : v)
        cout << e << " ";
    cout << endl;
    return 0;
}