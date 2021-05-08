//
// Created by 10578 on 2021/5/7.
//

#ifndef __CODE_LIBRARY_FOREACH_H__
#define __CODE_LIBRARY_FOREACH_H__

#include "utility"
#include "functional"
#include "type_traits"

template<typename Iter, typename Callable>
void foreach(Iter begin, Iter end, Callable op){
    while (begin != end) {
        op(*begin);
        ++begin;
    }
}

template<typename Iter, typename Callable, typename... Args>
void foreach_invoke(Iter begin, Iter end, Callable op, Args... args){
    while (begin != end) {
        std::invoke(op, args..., *begin);
        ++begin;
    }
}



#endif //__CODE_LIBRARY_FOREACH_H__
