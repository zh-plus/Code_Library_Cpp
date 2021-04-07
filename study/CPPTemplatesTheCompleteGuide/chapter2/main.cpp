//
// Created by 10578 on 2021/4/6.
//

#include "stack1.h"
#include "iostream"
#include "vector"
#include "deque"

int main(){
    Stack<int, std::deque> s;
    s.push(1);
    s.push(2);

    std::cout << s << std::endl;
}