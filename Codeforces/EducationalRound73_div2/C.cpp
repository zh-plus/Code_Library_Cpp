//
// Created by 10578 on 2019/8/20.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

int solve(int c, int m, int x){
    int result = min(c, m);
    result = min(result, (c + m + x) / 3);

    return result;
}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int q, c, m, x;
    cin >> q;

    while (q--) {
        cin >> c >> m >> x;
        cout << solve(c, m, x) << endl;
    }
}