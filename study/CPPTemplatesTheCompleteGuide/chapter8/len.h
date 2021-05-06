//
// Created by 10578 on 2021/4/21.
//

#ifndef __CODE_LIBRARY_LEN_H__
#define __CODE_LIBRARY_LEN_H__

#include "iostream"

template<typename T, unsigned N>
std::size_t len(T (&)[N]){
    return N;
}

template<typename T>
auto len(T const &t) -> decltype((void)(t.size()), typename T::size_type{}){
    return t.size();
}

std::size_t len(...){
    return 0;
}

#endif //__CODE_LIBRARY_LEN_H__
