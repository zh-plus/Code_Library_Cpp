//
// Created by 10578 on 2019/8/16.
//
#include <iostream>
#include <vector>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

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

double read_and_sum(int s) {
    Vector v(s);
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }

    return sum;
}

enum class Color {
    red = 1, blue, green,
};
enum Traffic_light {
    green, yellow, red,
};


int main() {
    BOOST_IO;

//    cout << read_and_sum(3) << endl;

    int i = 0;
    vector<int> v(10);
    Vector a = i;
    cout << a.size() << endl;

    Color x{0};
    Color y = Color::red;
    int z = (int) Color::blue;
    cout << (x == y) << endl
         << (int) x << endl
         << (int) z << endl;


    return 0;
}