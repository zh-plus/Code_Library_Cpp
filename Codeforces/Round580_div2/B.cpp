//
// Created by 10578 on 2019/8/18.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define coin(x) abs(abs(x) - 1)
#define ll long long


ll solve(int n, vector<int> A) {
    ll min_coins = 0;
    ll negative = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        min_coins += coin(A[i]);
        if (A[i] < 0) {
            negative++;
        } else if (A[i] == 0) {
            zero++;
        }
    }

    if (negative % 2 != 0 && zero == 0) {
        min_coins += 2;
    }

    return min_coins;
}


int main() {
    BOOST_IO;

    int n;

    ll result;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    result = solve(n, A);
    cout << result << endl;

    return 0;
}

