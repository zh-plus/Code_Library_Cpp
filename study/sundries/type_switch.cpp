//
// Created by 10578 on 10/29/2019.
//

#include <iostream>
#include <functional>
#include <cassert>

// Begin Ecatmur's code
template<typename T>
struct remove_class {
};
template<typename C, typename R, typename... A>
struct remove_class<R(C::*)(A...)> {
    using type = R(A...);
};
template<typename C, typename R, typename... A>
struct remove_class<R(C::*)(A...) const> {
    using type = R(A...);
};
template<typename C, typename R, typename... A>
struct remove_class<R(C::*)(A...) volatile> {
    using type = R(A...);
};
template<typename C, typename R, typename... A>
struct remove_class<R(C::*)(A...) const volatile> {
    using type = R(A...);
};

template<typename T>
struct get_signature_impl {
    using type = typename remove_class<
            decltype(&std::remove_reference<T>::type::operator())>::type;
};
template<typename R, typename... A>
struct get_signature_impl<R(A...)> {
    using type = R(A...);
};
template<typename R, typename... A>
struct get_signature_impl<R(&)(A...)> {
    using type = R(A...);
};
template<typename R, typename... A>
struct get_signature_impl<R(*)(A...)> {
    using type = R(A...);
};
template<typename T> using get_signature = typename get_signature_impl<T>::type;
// End ecatmur's code

// Begin type_case code
template<typename Base, typename FirstSubclass, typename... RestOfSubclasses>
void type_case(
        Base *base,
        FirstSubclass &&first,
        RestOfSubclasses &&... rest) {

    using Signature = get_signature<FirstSubclass>;
    using Function = std::function<Signature>;

    if (type_case_helper(base, (Function) first)) {
        return;
    } else {
        type_case(base, rest...);
    }
}

template<typename Base>
void type_case(Base *) {
    assert(false);
}

template<typename Base, typename T>
bool type_case_helper(Base *base, std::function<void(T *)> func) {
    if (T *first = dynamic_cast<T *>(base)) {
        func(first);
        return true;
    } else {
        return false;
    }
}
// End type_case code

class MyBaseClass {
public:
    virtual ~MyBaseClass() {}
};

class MyDerivedA : public MyBaseClass {
};

class MyDerivedB : public MyBaseClass {
};

int g = 0;


int main() {
    MyBaseClass *basePtr = new MyDerivedB();
    int ab = 1;

    type_case(basePtr,
              [&](MyDerivedA *a) {
                  std::cout << "is type A!" << std::endl;
                  ab = 2;
              },
              [&](MyDerivedB *b) {
                  std::cout << "is type B!" << std::endl;
                  ab = 3;
                  g = 2;
              });

    std::cout << ab << std::endl;
    std::cout << g << std::endl;

    return 0;
}