//
// Created by 10578 on 1/29/2020.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <algorithm>
#include <numeric>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;
using ll = long long;

int solve(ll a, ll m) {
	ll result = 0;

	ll gcd_am = gcd(a, m);
	for (ll x = 0; x < m; ++x) {
		if (gcd_am == gcd(a + x, m)) {
			++result;
		}
	}

	return result;
}

int main() {
	BOOST_IO

#ifdef LOCAL
	ifstream in("./in.txt");
	cin.rdbuf(in.rdbuf());
#endif

	int T;
	cin >> T;

	ll a, m;
	for (int i = 0; i < T; ++i) {
		cin >> a >> m;

		cout << solve(a, m) << endl;
	}
}