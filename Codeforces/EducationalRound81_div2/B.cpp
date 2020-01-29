//
// Created by 10578 on 1/29/2020.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

bool diff_sign(int x, int y) {
	return (x > 0 && y < 0) || (x < 0 && y > 0);
}

int reverse_traverse(int x, const string &s) {
	int result = 0;
	int diff = 0;
	for (int i = s.length() - 1; i >= 0; --i) {
		if (s[i] == '0') {
			--diff;
		} else {
			++diff;
		}

		if (diff == x) {
			++result;
		}
	}

	return result;
}

int traverse(int x, const string &s) {
	int result = 0;
	int diff = 0;
	for (auto &&c: s) {
		if (c == '0') {
			++diff;
		} else {
			--diff;
		}

		if (diff == x) {
			++result;
		}
	}

	return result;
}

int solve(int n, int x, const string &s) {
	int result = 0;

	int diff = 0;
	for (auto &&c: s) {
		if (c == '0') {
			++diff;
		} else {
			--diff;
		}
	}

	if (diff == 0 && x == 0) {
		return -1;
	}

	if (diff_sign(x, diff)) {
		result = traverse(x, s);

		if (x == 0) {
			++result;
		}
	} else {
		if (x >= diff) {
			int reminder = x % diff;
			result = reverse_traverse(reminder, s) + traverse(reminder, s);

			if (reminder == 0) {
				++result;
			}
		} else {
			result = traverse(x, s);

			if (x == 0) {
				++result;
			}
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

	int n, x;
	string s;
	for (int i = 0; i < T; ++i) {
		cin >> n >> x;
		cin >> s;

		cout << solve(n, x, s) << endl;
	}
}