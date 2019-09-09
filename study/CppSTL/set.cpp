//
// Created by 10578 on 9/9/2019.
//

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_set>

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

template<class T>
inline void hash_combine(std::size_t &seed, const T &v) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
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

namespace std {
    template<>
    struct hash<A> {
        size_t operator()(const A &a) const {
            size_t seed = 0;
            hash_combine(seed, a.u);
            hash_combine(seed, a.v);
            return seed;
        }
    };
}

int main() {
    BOOST_IO;

    unordered_set<A> set1;
    for (auto p: {pair{1, 2}, pair{1, 4}, pair{2, 3}, pair{2, 3}, pair{1, 2}}) {
        set1.emplace(p.first, p.second);
    }
    print_set(set1);

    return 0;
}