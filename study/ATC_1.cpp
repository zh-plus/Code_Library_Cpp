//
// Created by 10578 on 2019/8/16.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define st first
#define nd second


constexpr double square(double x) {
    return x * x;
}

void change_to_1(vector<int>* v)
{
    for (auto& x: *v)
        x = 1;
}

int count_x(const char* p, char x)
{
    if (p == nullptr)
        return 0;

    int count = 0;
    while (*p) {
        if (*p == x) {
            ++count;
        }
        ++p;
    }

    return count;
}

int main() {
    BOOST_IO;

    constexpr double x1 = 2.0;
    constexpr double d = square(x1);

    cout << d << endl;

    vector<int> v {1, 2, 3, 4, 5};
    change_to_1(&v);

    if (auto n = v.size())
    {
        cout << n << "  " << "True" << endl;
    } else {
        cout << n << "  " << "False" << endl;
    }

//    for(auto& x: v)
//        cout << x << endl;

//    const char* c1 = "12345123";
//    char c2 = '3';
//    cout << count_x(c1, c2) << endl;
//
//    pair<int, int> p = make_pair(1, 2);
//    cout << p.st << "  " << p.nd << endl;

    int* p = &v[0];
    cout << p << endl;

    int x = 2, y = 3;
    int &r1 = x, &r2 = y;
    r2 = x;
    cout << x << " " << y << endl;
    cout << r1 << " " << r2 << endl;

    int *p1 = NULL;
    cout << (p1 == nullptr) << endl;

    int in = 0b11;
    cout << in << endl;

    abcc = 10;


    return 0;
}