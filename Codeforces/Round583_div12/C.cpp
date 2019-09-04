//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

typedef long long ll;

using namespace std;

bool solve(int n, string brackets) {
    if (not n % 2) {
        return false;
    }

    int left = 0, right = 0, un_order = 0;
    for (auto c: brackets) {
        if (c == '(') {
            left++;
        } else {
            right++;
            if (left + un_order < right) {
                un_order++;
            }
        }
    }

    return left == right && un_order <= 1;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int n;
    cin >> n;

    string brackets;
    cin >> brackets;

    bool result = solve(n, brackets);
    cout << (result ? "Yes" : "No");

    return 0;
}