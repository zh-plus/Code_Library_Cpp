//
// Created by 10578 on 3/7/2020.
//

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

template<typename T>
class Allocator {
public:
    /**
     * Allocate space for n objects of type T.
     * @param n
     * @return
     */
    T *allocate(int n);

    /**
     * Deallocate space for n objects of type T starting at p.
     * @param p
     * @param n
     */
    void deallocate(T *p, int n);

    /**
     * Construct a T with the value v in p.
     * @param p
     * @param v
     */
    void construct(T *p, const T &v);

    void destroy(T *p);
};

/**
 * As Allocator is not implemented, using std::allocator instead.
 * @tparam T
 * @tparam A
 */
template<typename T, typename A = std::allocator<T>>
class Vector {
public:
    Vector() = default;

    explicit Vector(int s) : sz{static_cast<size_t>(s)}, elem{s ? new T[s] : nullptr} {
        cout << "Size constructor!" << endl;
    }

    Vector(initializer_list<T> lst) : sz{lst.size()}, elem{new T[sz]} {
        cout << "Initializer_list constructor!" << endl;
        copy(begin(lst), end(lst), elem);
    }

    // Copy constructor
    Vector(const Vector &obj) : sz{obj.sz}, elem{new T[sz]}, space{obj.sz} {
        cout << "Copy constructor!" << endl;
        if (space >= obj.sz) {
            copy(obj.elem, obj.elem + obj.sz, elem);
            sz = obj.sz;
        } else {
            auto *p = new T[obj.sz];
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


    T &operator[](int index) {
        return elem[index];
    }

    T operator[](int index) const {
        return elem[index];
    }

    T &at(int index) {
        if (index < 0 || index >= sz) {
            throw out_of_range("Index not at [0, " + to_string(sz) + ")!");
        }
        return elem[index];
    }

    [[nodiscard]] size_t size() const {
        return sz;
    }

    [[nodiscard]] size_t capacity() const {
        return space;
    }

    void reserve(size_t new_space) {
        if (new_space <= space) {
            return;
        }

        auto *p = alloc.allocate(new_space);
        copy(elem, elem + sz, p); // for (size_t i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);
        for (size_t i = 0; i < sz; ++i) {
            alloc.destroy(&elem[i]);
        }

        elem = p;
        space = new_space;
    }

    void resize(size_t new_size, T val = T()) {
        reserve(new_size);
        for (size_t i = sz; i < new_size; ++i) {
            alloc.construct(&elem[i], val);
        }

        // Free surplus memory
        for (size_t i = new_size; i < sz; ++i) {
            alloc.destroy(&elem[i]);
        }

        sz = new_size;
    }

    void push_back(T d) {
        if (space == 0) {
            reserve(8);
        } else if (space == sz) {
            reserve(space << 2u);
        }

        alloc.construct(&elem[sz], d);
        ++sz;
    }

private:
    size_t sz{0};
    T *elem{nullptr};
    size_t space{0};
    A alloc;
};

struct No_Default {
    No_Default() = delete;

    No_Default(int i) : value{i} {}

private:
    int value;
};


int main() {
    Vector<int *> v;
    v.resize(10, new int(10));

    Vector<int *> v1;
    v1 = v;

    vector<int> v2;
    v2.at(100);

//    begin(v);

    return 0;
}