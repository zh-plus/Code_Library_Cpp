//
// Created by 10578 on 2019/8/16.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <complex>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

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

    double &operator[](int i) {
        if (i < 0 or i >= sz) {
            throw out_of_range("Vector::operator[] out of range!");
        }

        return elem[i];
    }

    int size() { return sz; }
};

double my_pow(int base, int exponent = 2) {
    return pow(base, exponent);
}

int &bad() {
    int x = 0;
    return x;
}

pair<int, int> read_ints() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}


int main() {
    BOOST_IO;

    Vector v(4);
    v[0] = 0;
    v[1] = 1;
    v[3] = 2;

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

//    for (auto it = v.begin(), end = v.end(); it != end; it++) {
//        cout << *it << " ";
//    }

//    int a = 2, exponent = 3;
//    cout << my_pow(a, exponent);

//    auto[a, b] = read_ints();
//    cout << a << b << endl;

    map<string, int> m;
    m["s"] = 1;
    m["b"] = 2;

    for (auto &[key, value]: m) {
        ++value;
        cout << key << ": " << value << endl;
    }
    

    return 0;
}