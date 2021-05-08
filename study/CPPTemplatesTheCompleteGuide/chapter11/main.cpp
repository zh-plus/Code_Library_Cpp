//
// Created by 10578 on 2021/5/7.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "utility"
#include "foreach.h"

using namespace std;

void func(int i){
    cout << "func() called for: " << i << endl;
}

class FuncObj{
public:
    void memfunc(int i) const {
        cout << "FuncObj::op() called for: " << i << endl;
    }
};


int main() {
    auto v = vector<int>{1, 2, 3, 4};

//    for_each(v.begin(), v.end(), [](int x) {
//        cout << x << endl;
//    });

    foreach_invoke(v.begin(), v.end(), func);

    FuncObj obj;
    foreach_invoke(v.begin(), v.end(), &FuncObj::memfunc, obj);
    foreach_invoke(v.begin(), v.end(), [] (const string& prefix, int value){
        cout << prefix << value << endl;
    }, "- value: ");


    int i1 = 1, i2 = 2, i3 = 3, i4 = 4;
    pair<int&, int&> p1{i1, i2};
    pair<int&, int&> p2{i2, i3};

    p1 = p2;

    cout << i1 << endl;

    return 0;
}