//
// Created by 10578 on 2019/8/20.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

int solve(int n, vector<int> A, vector<int> B){
    int result = 0;


}

int main() {
    BOOST_IO

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int q = 0, n;
    cin >> q;

    while (q--) {
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i] >> B[i];
        }

        cout << solve(n, A, B);
    }
}