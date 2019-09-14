//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

int gcd(int a, int b) {
    int r;
    while (b) {
        r = b;
        b = a % b;
        a = r;
    }

    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int solve(int n, bitset<100> bits, vector<pair<int, int>> para) {
    size_t count = 0;

    for (int i = 0; i <= 5; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= para[j].second && (i - para[j].second) % para[j].first == 0) {
                bits[j] = !bits[j];
            }
        }
        count = max(count, bits.count());
    }

    int max_lcm = lcm(para[0].first, para[0].second);
    for (auto &[a, b]:para) {
        max_lcm = lcm(max_lcm, a + b);
    }

    for (int i = 6; i <= 3 * max_lcm; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i - para[j].second) % para[j].first == 0) {
                bits[j] = !bits[j];
            }
        }
        count = max(count, bits.count());
    }

    return count;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int n;
    cin >> n;

    string s;
    cin >> s;

    bitset<100> bits;
    for (int i = 0; i < n; ++i) {
        bits[i] = s[i] == '1';
    }

    vector<pair<int, int>> para(n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        para[i] = make_pair(a, b);
    }

    cout << solve(n, bits, para);
}