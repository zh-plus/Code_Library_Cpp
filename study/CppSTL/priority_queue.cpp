//
// Created by 10578 on 9/9/2019.
//

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

template<typename T>
void print_queue(T &q) {
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

class A {
public:
    int u;
    int v;

    A(int u, int v) : u{u}, v{v} {};

    bool operator<(const A &a2) const { return u < a2.u || (u == a2.u && v < a2.v); }

    friend ostream &operator<<(ostream &os, const A &obj) {
        os << obj.u << ":" << obj.v;
        return os;
    }

};


int main() {
    priority_queue<int> q1;

    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q1.push(n);

    print_queue(q1);

    priority_queue<int, vector<int>, greater<int> > q2;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q2.push(n);

    print_queue(q2);

    auto cmp1 = [](int left, int right) { return (left ^ 1u) < (right ^ 1u); };
    priority_queue<int, vector<int>, decltype(cmp1)> q3(cmp1);
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q3.push(n);

    print_queue(q3);

    auto cmp2 = [](A a1, A a2) { return a1.u < a2.u || (a1.u == a2.u && a1.v < a2.v); };
    priority_queue<A, vector<A>, decltype(cmp2)> q4(cmp2);
    for (auto p: {pair{1, 2}, pair{1, 4}, pair{2, 3}}) {
        q4.emplace(p.first, p.second);
    }

    print_queue(q4);

    priority_queue<A> q5;
    for (auto p: {pair{1, 2}, pair{1, 4}, pair{2, 3}}) {
        q5.emplace(p.first, p.second);
    }

    print_queue(q5);
}
