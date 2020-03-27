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

pair<string, string> solve(int n, string &s) {
    string first(s.size(), ' ');
    string second(s.size(), ' ');

    bool find_1 = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            first[i] = '0';
            second[i] = '0';
        }

        if (!find_1) {
            if (s[i] == '2') {
                first[i] = '1';
                second[i] = '1';
            } else if (s[i] == '1') {
                first[i] = '1';
                second[i] = '0';
                find_1 = true;
            }
        } else {
            if (s[i] == '2') {
                first[i] = '0';
                second[i] = '2';
            } else if (s[i] == '1') {
                first[i] = '0';
                second[i] = '1';
            }
        }
    }

    return make_pair(first, second);
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

    int T = 0;
    cin >> T;
    int n;
    string s{};
    while (T--) {
        cin >> n;
        cin >> s;
        auto result = solve(n, s);
        cout << result.first << endl
             << result.second << endl;
    }

    return 0;
}