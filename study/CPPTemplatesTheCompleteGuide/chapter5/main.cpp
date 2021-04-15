//
// Created by 10578 on 2021/4/14.
//

#include "iostream"
#include "vector"
#include "deque"
#include "stack2.h"

using namespace std;

template<typename T>
constexpr T pi{static_cast<T>(3.1415926)};


int main(){
    Stack<int, deque> s1{1, 2, 3, 4};
    Stack<float, deque> s2{2, 3, 4, 5.1};

    cout << s1 << endl << s2 << endl;

    s1 = s2;

    cout << s1;

    auto i = pi<int>;
    cout << i;
}