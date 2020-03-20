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
    using iterator = T*;

    Vector() = default;

    explicit Vector(int s) : sz{static_cast<size_t>(s)}, elem{s ? new T[s] : nullptr} {
        cout << "Size constructor!" << endl;
    }

    Vector(initializer_list<T> lst) : sz{lst.size()}, elem{new T[sz]} {
        using std::begin, std::end;

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

    iterator begin(){
        return elem;
    }

    iterator end(){
        return elem + sz;
    }

    T front(){
        return *begin();
    }

    T back(){
        return *(end() - 1);
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
        reserve(space == 0 ? 8 : space << 1u);

        alloc.construct(&elem[sz], d);
        ++sz;
    }

    iterator insert(iterator p, const T& val){
        int index = distance(begin(), p);
        if (sz == space) {
            reserve(space == 0 ? 8 : space << 1u);
        }

        alloc.construct(elem + sz, back());

        ++sz;
        iterator pp = begin();
        advance(pp, index);
        for(auto pos = end() - 1; pos != pp; --pos){
            *pos = *(pos - 1);
        }
        *(pp) = val;

        return pp;
    }

    iterator erase(iterator p){
        if (p == end()) {
            return p;
        }

        for (auto pos = p + 1; pos != end(); ++pos) {
            *(pos - 1) = *pos;
        }
        alloc.destroy(&*(end() - 1));
        --sz;

        return p;
    }

private:
    size_t sz{0};
    iterator elem{nullptr};
    size_t space{0};
    A alloc;
};

struct No_Default {
    No_Default() = delete;

    explicit No_Default(int i) : value{i} {}

private:
    int value;
};


int main() {
    Vector<int> v{1, 2, 3, 4};
    v.erase(begin(v));
    v.insert(begin(v) + 1, 10);

    for(auto &&x: v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}