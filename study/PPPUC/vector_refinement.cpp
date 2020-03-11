//
// Created by 10578 on 3/7/2020.
//

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Vector {
public:
    Vector() = default;

    explicit Vector(int s) : sz{static_cast<size_t>(s)}, elem{s ? new double[s] : nullptr} {
        cout << "Size constructor!" << endl;
    }

    Vector(initializer_list<double> lst) : sz{lst.size()}, elem{new double[sz]} {
        cout << "Initializer_list constructor!" << endl;
        copy(begin(lst), end(lst), elem);
    }

    // Copy constructor
    Vector(const Vector &obj) : sz{obj.sz}, elem{new double[sz]}, space{obj.sz} {
        cout << "Copy constructor!" << endl;
        if (space >= obj.sz) {
            copy(obj.elem, obj.elem + obj.sz, elem);
            sz = obj.sz;
        } else {
            auto *p = new double[obj.sz];
            copy(obj.elem, obj.elem + obj.sz, p);

            delete[] elem;
            elem = p;
            space = sz = obj.sz;
        }
    }

    // Copy assignment
    Vector &operator=(const Vector &obj) {
        cout << "Copy assignment" << endl;
        if (this != &obj) {
            Vector temp(obj);
            swap(*this, temp);
        }

        return *this;
    }

    // Move constructor
    Vector(Vector &&obj) noexcept: Vector() {
        cout << "Move constructor" << endl;
        swap(*this, obj);
    }

    // Move assignment
    Vector &operator=(Vector &&obj) noexcept {
        cout << "Move assignment" << endl;
        swap(*this, obj);

        return *this;
    }

    friend void swap(Vector &first, Vector &second) {
        using std::swap;

        swap(first.sz, second.sz);
        swap(first.elem, second.elem);
    }

    ~Vector() {
        cout << "Destructor!" << endl;
        delete[] elem;
    }


    double &operator[](int index) {
        return elem[index];
    }

    double operator[](int index) const {
        return elem[index];
    }

    double &at(int index) {
        return elem[index];
    }

    [[nodiscard]] size_t size() const {
        return sz;
    }

    [[nodiscard]] size_t capacity() const {
        return space;
    }

    void reserve(int new_space) {
        if (new_space <= space) {
            return;
        }

        auto *p = new double[new_space];
        copy(elem, elem + sz, p);
        delete[] elem;

        elem = p;
        space = new_space;
    }

    void resize(int new_size) {
        reserve(new_size);
        for (int i = sz; i < new_size; ++i) {
            elem[i] = 0;
        }

        sz = new_size;
    }

    void push_back(double d) {
        if (space == 0) {
            reserve(8);
        } else if (space == sz) {
            reserve(space << 2);
        }

        elem[sz++] = d;
    }

private:
    size_t sz{0};
    double *elem{nullptr};
    size_t space{0};
};


int main() {
    size_t i = 5;
    cout << (i << 1) << endl;

    vector<int> v;
    v.push_back(1);

    return 0;
}