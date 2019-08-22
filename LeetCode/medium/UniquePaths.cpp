//
// Created by 10578 on 2019/8/19.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

typedef long long ll;

using namespace std;

class Solution {
public:
    /**
     * In big number condition, using C(b, s) = (b - s + 1) * C(b, s - 1) / s to prevent long long out of range.
     */
    ll combination(int b, int s){
        if (s > b / 2) {
            s = b - s;
        }

        if (s > 3) {
            return (b - s + 1) * combination(b, s - 1) / s;
        }

        ll factor = 1;
        for (int i = 0; i < s; ++i) {
            factor *= b--;
        }

        ll dominator = 1;
        for (; s > 0; --s) {
            dominator *= s;
        }

        return factor / dominator;
    }

    /**
     * Return C(m + n - 2, n - 1)
     */
    ll uniquePaths(int m, int n) {
        return combination(m + n - 2, n - 1);
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int m, n;
    cin >> m >> n;

    Solution s;
    cout << s.uniquePaths(m, n);

    return 0;
}