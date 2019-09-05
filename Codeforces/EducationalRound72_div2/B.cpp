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

int solve(int n, int x, vector<int> D, vector<int> H) {
    int result = 0;

    int max_hurt = INT32_MIN, max_damage = INT32_MIN;
    for (int i = 0; i < n; ++i) {
        max_damage = max(max_damage, D[i]);
        max_hurt = max(max_hurt, D[i] - H[i]);
    }

    if (max_damage >= x) {
        return 1;
    }

    if (max_hurt <= 0) {
        return -1;
    }

    x -= max_damage;
    result++;

    result += (int) ceil(x / (double) max_hurt);

    return result;
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<int> D, H;
    int T, n, x;
    cin >> T;

    while (T--) {
        cin >> n >> x;
        D.resize(n);
        H.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> D[i] >> H[i];
        }

        cout << solve(n, x, D, H) << endl;
    }

    return 0;
}