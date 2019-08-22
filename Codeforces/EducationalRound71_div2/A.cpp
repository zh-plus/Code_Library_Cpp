//
// Created by 10578 on 2019/8/20.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bitset>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//#define LOCAL


using namespace std;


int solve(const int &b, const int &p, const int &f, const int &h, const int &c) {
    int more, less, more_num, less_num, bun_num = b;
    if (h >= c) {
        more = h;
        more_num = p;
        less = c;
        less_num = f;
    } else {
        more = c;
        more_num = f;
        less = h;
        less_num = p;
    }

    if (bun_num - 2 * more_num <= 0) {
        //bun not enough, return all more price
        return min(more_num, bun_num / 2) * more;
    } else {
        return more_num * more + min(less_num, (bun_num - 2 * more_num) / 2) * less;
    }
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int T, b, p, f, h, c, result;
    cin >> T;

    while (T--) {
        cin >> b >> p >> f;
        cin >> h >> c;
        result = solve(b, p, f, h, c);
        cout << result << endl;
    }

    return 0;
}