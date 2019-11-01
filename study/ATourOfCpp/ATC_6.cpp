//
// Created by 10578 on 2019/8/16.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <map>
#include <complex>
#include <algorithm>
#include <numeric>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

template<typename T>
class Vector {
    T *elem;
    int sz;

public:
    using value_type = T;

    explicit Vector(int s) : elem{new T[s]}, sz{s} {
        if (s < 0) {
            throw length_error("Vector constructor: negative size");
        }

        for (int i = 0; i < s; ++i) {
            elem[i] = 0;
        }

        cout << "Initialization done!" << endl;
    }

    Vector(initializer_list<T> lst) : elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {
        copy(lst.begin(), lst.end(), elem);
    }

    ~Vector() {
        delete[] elem;
    }

    T &operator[](int i) const {
        if (i < 0 or i >= sz) {
            throw out_of_range("Vector::operator[] out of range!");
        }

        return elem[i];
    }

    Vector(const Vector &v) : elem{new T[v.size()]}, sz{v.size()} {
        for (int i = 0; i < v.size(); ++i) {
            elem[i] = v.elem[i];
        }
    }

    int size() const { return sz; }
};

template<typename T>
class Container {
public:
    virtual T &operator[](int) = 0;

    virtual int size() const = 0;

    virtual ~Container() = default;
};

template<typename T>
class Vector_container : public Container<T> {
public:
    explicit Vector_container(int s) : v(s) {}

    Vector_container(initializer_list<T> lst) : v{lst} {}

    ~Vector_container() override = default;

    T &operator[](int i) override { return v[i]; }

    int size() const override { return v.size(); }

private:
    Vector<T> v;
};

template<typename T>
class List_container : public Container<T> {
public:
    List_container() = default;;

    List_container(initializer_list<T> lst) : ld{lst} {};

    ~List_container() override {};

    T &operator[](int i) override {
        for (auto &x: ld) {
            if (i-- == 0) {
                return x;
            }
        }
        throw out_of_range("List container!");
    }

    int size() const override { return ld.size(); }

private:
    list<T> ld;
};

template<typename T>
void use(Container<T> &container) {
    for (int i = 0, sz = container.size(); i < sz; ++i) {
        cout << container[i] << " ";
    }
    cout << endl;
}

template<typename T>
void print_vector(const Vector<T> &v) {
    for (int i = 0, sz = v.size(); i < sz; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename Sequence, typename Value>
Value sum(const Sequence &s, Value value) {
    for_each(s.begin(), s.end(), [&](Value v) {
        value += v;
    });

    return value;
}



template<typename C>
using Value_type = typename C::value_type;

template<typename V>
void algo(V &v) {
    vector<typename V::value_type> vec;
}


int main() {
    BOOST_IO;

    vector v1{1, 2, 3};
    vector v2 = v1;
    v2[0] = -1;
//    print_vector(v1);
//    print_vector(v2);

    cout << 1 / 3 * 3 << endl;

    cout << sum(v1, 0) << endl;

    for_each(v1.begin(), v2.begin(), [](int &i) { i += 1; });

    for (auto &x: v1) {
        cout << x << " ";
    }
    cout << endl;

    int value = -1;
    vector<int> v3 = [&] {
        return vector<int>(3, value);
    }();

    int n;
    advance()
    while (--n) {}


    return 0;
}