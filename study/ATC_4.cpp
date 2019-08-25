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

int main() {
    BOOST_IO;

    vector<int> v;
    complex<int> c;
    

    return 0;
}