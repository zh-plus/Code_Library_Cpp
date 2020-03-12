//
// Created by 10578 on 3/12/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

int solve(string &s) {
    int max_L = 0;
    int temp = 0;
    s += '*';
    for (auto &&c: s) {
        if (c == 'L') {
            temp += 1;
        } else if (temp) {
            max_L = max(temp, max_L);
            temp = 0;
        }
    }

    return max_L + 1;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int T = 0;
    cin >> T;
    string s{};
    while (T--) {
        cin >> s;

        cout << solve(s) << endl;
    }

    return 0;
}