//
// Created by 10578 on 3/12/2020.
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

int solve(int a, int b) {
    if (a < b) {
        return b - a;
    }

    int temp = b;
    while (a > temp) {
        temp += b;
    }

    return temp - a;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

    int T;
    cin >> T;
    int a, b;
    while (T--) {
        cin >> a >> b;

        cout << solve(a, b) << endl;
    }

    return 0;
}