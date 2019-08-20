//
// Created by 10578 on 2019/8/16.
//
#include <iostream>
#include <vector>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Vector {
    double *elem;
    int sz;

public:
    Vector(int s) : elem{new double[s]}, sz{s} {
        cout << "Initialization done!" << endl;
    }

    double &operator[](int i) { return elem[i]; }

    int size() { return sz; }
};

int main() {
    BOOST_IO;

    Vector v(3);
    v[0] = 0;
    v[1] = 1;
    v[4] = 2;

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }


//    for (auto it = v.begin(), end = v.end(); it != end; it++) {
//        cout << *it << " ";
//    }

    return 0;
}