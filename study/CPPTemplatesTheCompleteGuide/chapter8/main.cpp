//
// Created by 10578 on 2021/4/20.
//

#include "iostream"
#include "vector"
#include "len.h"

using namespace std;

int main(){
    int a[10];
    cout << len(a) << endl;
    cout << len("amp") << endl;

    vector<int> v{1, 2, 3};
    cout << len(v) << endl;

    int *p = &a[0];
    cout << len(p) << endl;

    std::allocator<int> x;
    cout << len(x) << endl;

    return 0;
}