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

vector<vector<char>> solve(int n) {
    vector<vector<char>> result(n, vector<char>(n, 'B'));
    for (int i = 0; i < n; ++i) {
        for (int j = i % 2; j < n; j += 2) {
            result[i][j] = 'W';
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

    int n;
    cin >> n;

    auto result = solve(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j];
        }
        cout << endl;
    }
}