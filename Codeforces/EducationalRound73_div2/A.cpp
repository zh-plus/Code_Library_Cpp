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
#include <numeric>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;
using ll = long long;

bool solve(const vector<int> &nums) {
    ll sum = 0;
    for (auto &num: nums) {
        sum += num <= 2048 ? num : 0;
    }

    return sum >= 2048;
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int q = 0, n;
    cin >> q;

    while (q--) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        bool result = solve(nums);
        cout << (result ? "YES" : "NO") << endl;
    }
}