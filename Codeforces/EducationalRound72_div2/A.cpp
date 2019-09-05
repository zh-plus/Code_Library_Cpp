//
// Created by 10578 on 2019/8/20.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <cmath>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

int solve(int s, int i, int e) {
    if (s + e <= i) {
        return 0;
    } else if (s <= i) {
        e -= (i + 1 - s);
        s = i + 1;
    }

    int smaller = i + e - s;
    int order = max(0, (int) ceil((smaller + 1) / 2.0));

    return e + 1 - order;
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int T, s, i, e;
    cin >> T;

    while (T--) {
        cin >> s >> i >> e;
        cout << solve(s, i, e) << endl;
    }

    return 0;
}