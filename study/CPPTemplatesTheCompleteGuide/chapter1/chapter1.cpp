//
// Created by 10578 on 2021/4/6.
//
#include "iostream"
#include "algorithm"
#include "type_traits"

template<typename T1, typename T2>
auto max(T1 a, T2 b) -> std::common_type_t<T1, T2>{
    return b < a ? a : b;
}

int main(){
    auto a = max(1, 0.0);

    std:: cout << " test !" << std::endl;

    return 0;
}