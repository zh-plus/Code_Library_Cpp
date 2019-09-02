//
// Created by 10578 on 2019/8/16.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <complex>


#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


using namespace std;


class Vector {
    double *elem;
    int sz;

public:
    Vector(int s) : elem{new double[s]}, sz{s} {
        if (s < 0) {
            throw length_error("Vector constructor: negative size");
        }

        cout << "Initialization done!" << endl;
    }

    Vector(initializer_list<double> lst) : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
        copy(lst.begin(), lst.end(), elem);
    }

    ~Vector() {
        delete[] elem;
    }

    double &operator[](int i) {
        if (i < 0 or i >= sz) {
            throw out_of_range("Vector::operator[] out of range!");
        }

        return elem[i];
    }

    int size() { return sz; }
};

class Container {
public:
    virtual double &operator[](int) = 0;

    virtual int size() const = 0;

    virtual ~Container() = default;
};

class Vector_container : public Container {
public:
    Vector_container(int s) : v(s) {}


private:
    Vector v;
};

int main() {
    BOOST_IO;

    vector<double> v{1, 2, 3};
//    for (double d; cin >> d;) {
//        v.push_back(d);
//    }
    vector<double> m(v.size());
    copy(v.begin(), v.end(), m.begin());
    for (auto x: m) {
        cout << x << " ";
    }
    cout << endl;

    int x = 0;
    const int *a = &x;
    int *b = const_cast<int *>(a);
    *b = 1;
    cout << x;

    return 0;
}