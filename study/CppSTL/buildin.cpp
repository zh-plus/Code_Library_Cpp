//
// Created by 10578 on 9/11/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <random>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

namespace std {
    ostream &operator<<(ostream &os, const pair<int, string> &p) {
        return os << "(" << p.first << ", " << p.second << ")";
    }
}


int main() {
    BOOST_IO;

    vector<pair<int, string>> v1{
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
            {5, "five"}};

    map<int, string> m;

    copy(begin(v1), end(v1), inserter(m, begin(m)));

    ostream_iterator<pair<int, string>> shell_it{cout, ", "};

    copy(begin(m), end(m), shell_it);
    cout << '\n';

    vector<int> v2{100, 400, 200};

    vector<int> prefix_sum(v2.size());
    partial_sum(v2.begin(), v2.end(), prefix_sum.begin());
    for (auto &x: prefix_sum) {
        cout << x << " ";
    }
    cout << endl;

    int sum{0};
    for (int i : v2) { sum += i; }

    cout << sum << '\n';
    cout << accumulate(begin(v2), end(v2), 1, [](int x, int y){return x * y;}) << '\n';

    mt19937 g {random_device{}()};
    for (int T = 40; T; T--) {
        cout << g() << endl;
    }

    return 0;
}