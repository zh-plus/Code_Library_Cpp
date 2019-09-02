//
// Created by 10578 on 8/25/2019.
//

#include <vector>
#include <iostream>
#include <fstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//#define LOCAL

using namespace std;

int solve(int a, int b, int n) {
    n %= 3;
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        return a ^ b;
    }
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int T, a, b, n;
    cin >> T;
    while (T--) {
        cin >> a >> b >> n;
        int result = solve(a, b, n);
        cout << result << endl;
    }

    return 0;
}