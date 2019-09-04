//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

typedef long long ll;

using namespace std;

int solve(int n, int d, int e) {
    int c = 5 * e;
    

}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int n, d, e;
    cin >> n >> d >> e;

    int result = solve(n, d, e);
    cout << result;

    return 0;
}