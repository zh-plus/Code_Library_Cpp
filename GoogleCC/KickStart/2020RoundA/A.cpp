//
// Created by 10578 on 3/22/2020.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

//#define DEBUG
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define BOOST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int solve(int B, vector<int> A) {
    sort(A.begin(), A.end());
    vector<int> pre_sum(A.size());
    partial_sum(A.begin(), A.end(), pre_sum.begin());

    auto index = upper_bound(pre_sum.begin(), pre_sum.end(), B);
    int result = distance(pre_sum.begin(), index);

    return result;
}

int main() {
    BOOST_IO;

#ifdef DEBUG
    ALTER_IN("../in.txt")
#endif

    int T, N, B, result;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> B;
        vector<int> A(N);

        copy_n(istream_iterator<int>(cin), N, A.begin());

        result = solve(B, A);
        cout << "Case #" << i << ": " << result << endl;
    }

    return 0;
}
