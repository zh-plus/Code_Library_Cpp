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
#include <unordered_set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

bool dfs_a(int a, int b, int smaller, vector<int> avail);
bool dfs_b(int a, int b, int smaller, vector<int> avail);

bool dfs_a(int a, int b, int smaller, vector<int> avail) {
    for (int i = 0, sz = avail.size(); i < sz; ++i) {
        vector<int> rm_avail(avail);
        rm_avail.erase(rm_avail.begin() + i);
        for (int j = 0; j <= avail[i] - a; ++j) {
            vector<int> new_avail(rm_avail);

            if (j >= smaller)
                new_avail.push_back(j);
            if (int oppo = avail[i] - a - i; oppo >= smaller)
                new_avail.push_back(oppo);

            if (dfs_b(a, b, smaller, new_avail))
                return true;
        }
    }

    return false;
}

bool dfs_b(int a, int b, int smaller, vector<int> avail) {
    for (int i = 0, sz = avail.size(); i < sz; ++i) {
        vector<int> rm_avail(avail);
        rm_avail.erase(rm_avail.begin() + i);
        for (int j = 0; j <= avail[i] - b; ++j) {
            vector<int> new_avail(rm_avail);

            if (j >= smaller)
                new_avail.push_back(j);
            if (int oppo = avail[i] - b - i; oppo >= smaller)
                new_avail.push_back(oppo);

            if (dfs_a(a, b, smaller, new_avail))
                return false;
        }
    }

    return true;
}

bool solve(int a, int b, string &s) {
    vector<int> avail;
    int smaller = min(a, b);
    int temp = 0;
    for (char i : s) {
        if (i == 'X') {
            if (temp >= smaller)
                avail.push_back(temp);
            temp = 0;
        } else {
            temp++;
        }
    }

    return dfs_a(a, b, smaller, avail);
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int q, a, b;
    string s;
    cin >> q;

    while (q--) {
        cin >> a >> b;
        cin >> s;
        bool result = solve(a, b, s);
        cout << (result ? "YES" : "NO") << endl;
    }
}