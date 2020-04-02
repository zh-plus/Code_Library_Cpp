//
// Created by 10578 on 3/31/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

    int T;
    cin >> T;
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    while (T--) {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        int horizontal = b - a;
        int vertical = d - c;

        if (y2 - y == 0 && vertical > 0 ||
            y1 - y == 0 && vertical < 0 ||
            x2 - x == 0 && horizontal > 0 ||
            x1 - x == 0 && horizontal < 0) {
            cout << "NO" << endl;
            continue;
        }

        int result_x = x + horizontal;
        int result_y = y + vertical;
        bool result = !(result_x > x2 || result_x < x1 || result_y > y2 || result_y < y1);

        if (result) {
            if (y2 - y == 0 && y1 - y == 0 && c != 0 && d != 0 ||
                x2 - x == 0 && x1 - x == 0 && a != 0 && b != 0) {
                    result = false;
            }
        }

        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}