//
// Created by 10578 on 3/31/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    for (int i = 0; i < B.size(); ++i) {
        A[i] -= B[i];
    }

    int count = 0;
    int sz = A.size();
    for (int i = 0; i < sz; ++i) {
        for (int j = i + 1; j < sz; ++j) {
            if (A[i] + A[j] > 0) {
                ++count;
            }
        }
    }

    return count;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("../in.txt");
#endif

    int n = 0;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    cout << solve(A, B) << endl;

    return 0;
}