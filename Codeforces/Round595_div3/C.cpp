//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using ll = long long;

using namespace std;

bool is_distinct(ll n){
    unordered_set<int> used_exp;
    ll num = n;
    double exp = log(num) / log(3);
    int tmp = pow(3, ceil(exp));
    if (tmp <= num) {
        exp = ceil(exp);
    }

    while (floor(exp) != 0 && num != 0) {
        if (used_exp.find(floor(exp)) == used_exp.end()) {
            used_exp.insert(floor(exp));
        } else {
            return false;
        }

        int temp = pow(3, floor(exp));
        num -= temp;
        exp = min(log(num) / log(3), exp - 1);
    }

    if (num != 0 && used_exp.find(0) == used_exp.end()) {
        num -= 1;
        used_exp.insert(0);
    }

    return num == 0;
}


ll solve(ll n) {
    unordered_set<int> used_exp;

    ll result = 0;
    ll num = n;
    double exp = log(num) / log(3);
    int tmp = pow(3, ceil(exp));
    if (tmp <= num) {
        exp = ceil(exp);
    }

    while (floor(exp) != 0 && num != 0) {
        used_exp.insert(floor(exp));
        int temp = pow(3, floor(exp));
        num -= temp;
        exp = min(log(num) / log(3), exp - 1);
    }

    if (num != 0 && used_exp.find(0) == used_exp.end()) {
        num -= 1;
        used_exp.insert(0);
    }

    if (num == 0) {
        return n;
    }

    int add_exp = 0;
    for (int i = 0; i < INT32_MAX; ++i) {
        if (used_exp.find(i) == used_exp.end()) {
            add_exp = i;
            break;
        }
    }

    if (used_exp.empty()) {
        return pow(3, 0);
    }

    if (add_exp > *max_element(used_exp.begin(), used_exp.end())) {
        return pow(3, add_exp);
    }

    for (const auto &x: used_exp) {
        result += pow(3, x);
    }
    result += pow(3, add_exp);

    return result;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int q;
    cin >> q;

    while (q--) {
        ll n;
        cin >> n;

        cout << solve(n) << endl;
    }

//    for (int i = 1; i <= 1000000; ++i) {
//        cout << i << endl;
//        if (!is_distinct(solve(i))) {
//            cout << i << " " << solve(i) << endl;
//        }
//    }

//    is_distinct(243);

    return 0;
}