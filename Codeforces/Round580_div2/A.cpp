//
// Created by 10578 on 2019/8/18.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

pair<int, int> solve(int n, vector<int> A, int m, vector<int> B) {
    set<int> a_set(A.begin(), A.end());
    set<int> b_set(B.begin(), B.end());
//    set<int> ab_set;
//    set_union(a_set.begin(), a_set.end(), b_set.begin(), b_set.end(), inserter(ab_set, ab_set.begin()));

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum = A[i] + B[j];

            if (a_set.find(sum) == a_set.end() && b_set.find(sum) == b_set.end()) {
                return make_pair(A[i], B[j]);
            }
        }
    }
}


int main() {
    BOOST_IO;

    int n, m;

    pair<int, int> result;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    result = solve(n, A, m, B);
    cout << result.first << " " << result.second << endl;

    return 0;
}

