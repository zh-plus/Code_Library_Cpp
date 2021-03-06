//
// Created by 10578 on 9/9/2019.
//

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include <set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

template<typename T>
void print_set(T &s) {
    for (auto &x: s) {
        cout << x << " ";
    }
    cout << endl;
}

class A {
public:
    int u, v;

    A(int u, int v) : u{u}, v{v} {};

    bool operator==(const A &obj) const {
        return u == obj.u && v == obj.v;
    }

    friend ostream &operator<<(ostream &os, const A &obj) {
        os << obj.u << ":" << obj.v;
        return os;
    }
};


int main() {
    BOOST_IO;

    auto cmp = [] (const A &a1, const A &a2) -> bool {
        return tie(a1.u, a1.v) < tie(a2.u, a2.v);
    };
    set<A, decltype(cmp)> set1;
    for (auto p: {A{1, 2}, A{1, 4}, A{2, 3}, A{2, 3}, A{1, 2}}) {
        cout << "Inserting " << p << endl;
        set1.insert(p);
    }
    print_set(set1);

//    auto comp = [](int x, int y) { return x < y; };
//    auto set = std::set<int, decltype(comp)>(comp);
//
//    set.insert(1);
//    set.insert(10);
//    set.insert(1); // Dupe!
//    set.insert(2);
//
//    std::copy(set.begin(), set.end(), ostream_iterator<int>(std::cout, "\n"));

    return 0;
}