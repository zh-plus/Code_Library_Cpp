//
// Created by 10578 on 2019/8/20.
//

#include <vector>
#include <iostream>
#include <fstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL
#define LEN 500000

typedef long long ll;

using namespace std;
int a[LEN];

ll solve(int x, int y) {
    ll result = 0;
    for (int i = 1; i <= LEN; ++i) {
        if (a[i] % x == y) {
            result += a[i];
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

    for (int i = 0; i <= LEN; ++i) {
        a[i] = 0;
    }

    int T, type, x, y;
    ll result;
    cin >> T;
    while (T--) {
        cin >> type >> x >> y;
        if (type == 1) {
            a[x] += y;
            cout << a[x] << endl;
        } else {
            result = solve(x, y);
            cout << result << endl;
        }
    }

    return 0;
}