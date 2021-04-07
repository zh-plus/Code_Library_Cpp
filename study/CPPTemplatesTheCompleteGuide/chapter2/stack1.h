//
// Created by 10578 on 2021/4/6.
//

#ifndef __CODE_LIBRARY_STACK1_H__
#define __CODE_LIBRARY_STACK1_H__

#include "vector"
#include "cassert"
#include "iostream"

template<typename T, template<typename...> class C>
class Stack;

template<typename T, template<typename...> class C>
std::ostream &operator<<(std::ostream &os, Stack<T, C> const &s);

template<typename T, template<typename...> class C>
class Stack {
private:
    C<T> elems;

public:
    void push(T const &elem);
    T pop();
    T const & top() const;
    bool empty() const{
        return elems.empty();
    }

    friend std::ostream& operator<< <T>(std::ostream &os, Stack<T, C> const &s);
};

template<typename T, template<typename...> class C>
void Stack<T, C>::push(T const &elem) {
    elems.push_back(elem);
}

template<typename T, template<typename...> class C>
T Stack<T, C>::pop() {
    assert(!elems.empty());
    T temp = top();
    elems.pop_back();
    return temp;
}

template<typename T, template<typename...> class C>
T const & Stack<T, C>::top() const {
    assert(!elems.empty());
    return elems.back();
}

template<typename T, template<typename...> class C>
std::ostream &operator<<(std::ostream &os, Stack<T, C> const &s) {
    for (auto &&x: s.elems) {
        os << x << " ";
    }
    os << std::endl;

    return os;
}

#endif //__CODE_LIBRARY_STACK1_H__
