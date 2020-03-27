//
// Created by 10578 on 3/12/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
#include <cmath>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL


using namespace std;
using ll = long long;

double newton(ll n, ll k) {
    double x0 = 5;

    for (int i = 0; i < 25; ++i) {
        x0 -= (pow(x0, 2) - x0 - 2 * k) / (2 * x0 - 1);
    }

    ll temp;
    if (temp = floor(x0);  pow(temp, 2) - temp - 2 * k == 0) {
        x0 = temp;
    } else if (temp = ceil(x0);  pow(temp, 2) - temp - 2 * k == 0) {
        x0 = temp;
    }

    return x0;
}

string solve(int n, ll k) {
    double root = newton(n, k);
    ll first = floor(root);

    ll pre = 0;
    if (first % 2 == 0) {
        pre = first / 2;
        pre *= (first - 1);
    } else {
        pre = (first - 1) / 2;
        pre *= first;
    }

    if (root > first) {
        first++;
    }

    ll second = (k - pre) == 0 ? first - 1 : k - pre;
    string result(n, 'a');
    result[n - first] = 'b';
    result[n - second] = 'b';

    return result;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

    int T = 0;
    cin >> T;
    ll n, k;
    while (T--) {
        cin >> n >> k;

        cout << solve(n, k) << endl;
    }

    return 0;
}