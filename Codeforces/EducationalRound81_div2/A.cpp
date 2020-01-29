//
// Created by 10578 on 1/29/2020.
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

string solve(int n) {
	int one_num = n / 2;
	int reminder = n % 2;

	string result(one_num, '1');

	if (reminder != 0) {
		result.front() = '7';
	}

	return result;
}

int main() {
	BOOST_IO

#ifdef LOCAL
	ifstream in("./in.txt");
	cin.rdbuf(in.rdbuf());
#endif

	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << solve(n) << endl;
	}

	return 0;
}