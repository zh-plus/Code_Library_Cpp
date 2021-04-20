//
// Created by 10578 on 2021/4/15.
//

#ifndef __CODE_LIBRARY_PERSON_H__
#define __CODE_LIBRARY_PERSON_H__

#include "utility"
#include "string"
#include "iostream"
#include "type_traits"

template<typename T>
using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;

class Person {
private:
    std::string name;
public:
    // Generic normal constructor from name.
    template<typename Str,
            typename = EnableIfString<Str>>
    explicit Person(Str &&s) : name(std::forward<Str>(s)) {
        std::cout << "Generic constructor" << std::endl;
    }

    // copy constructor.
    template<typename Str>
    explicit Person(Person const &p) : name{p.name} {}

    // move constructor.
    template<typename Str>
    explicit Person(Person &&p) {
        swap(*this, p);
    }

    friend void swap(Person &first, Person &second) {
        std::cout << "Swap" << std::endl;

        std::swap(first.name, second.name);
    }

};

#endif //__CODE_LIBRARY_PERSON_H__
