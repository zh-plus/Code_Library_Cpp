//
// Created by 10578 on 3/31/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;


int get_divisor(int n) {
    for (int i = 2; i <= (n >> 1); ++i) {
        if (n % i == 0) {
            return i;
        }
    }

    return 1;
}

void solve(int n, vector<int> &v) {
    set<int> color_set;
    vector<int> dividers(v.size());

    for (int i = 0; i < v.size(); ++i) {
        dividers[i] = get_divisor(v[i]);
        color_set.insert(dividers[i]);
    }

    map<int, int> divider_to_color;
    int color = 1;
    for (auto &&divider : dividers) {
        if (divider_to_color.find(divider) == divider_to_color.end()) {
            divider_to_color[divider] = color++; // color from 1 - size
        }
    }

    cout << divider_to_color.size() << endl;

    for (auto &&x: dividers) {
        cout << divider_to_color[x] << " ";
    }
    cout << endl;

//    copy(colors.begin(), colors.end(), ostream_iterator<int>(cout, " "));
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

    int T = 0;
    cin >> T;
    int n;
    vector<int> v;
    while (T--) {
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        solve(n, v);
    }

    return 0;
}