//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

typedef long long ll;

using namespace std;

ll solve(ll n, ll m) {
    ll mod = 0;
    for (ll j = 0; j <= m * 10; j += m) {
        mod += (j % 10);
    }

    ll result = 0;
    result += (n / (10 * m)) * mod;
    n %= m * 10;

    for (ll i = 0; i <= n; i += m) {
        result += (i % 10);
    }

    return result;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    ll q, n, m, result;
    cin >> q;
    while (q--) {
        cin >> n >> m;
        result = solve(n, m);
        cout << result << endl;
    }

    return 0;
}