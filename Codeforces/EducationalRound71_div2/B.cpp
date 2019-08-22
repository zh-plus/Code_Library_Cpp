//
// Created by 10578 on 2019/8/20.
//

#include <vector>
#include <iostream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//#define LOCAL

typedef long long ll;

using namespace std;

inline int filter(int **&A, int i, int j) {
    return A[i][j] + A[i][j + 1] + A[i + 1][j] + A[i + 1][j + 1];
}

inline void fill(int **&A, int i, int j){
    A[i][j] = 1;
    A[i][j + 1] = 1;
    A[i + 1][j] = 1;
    A[i + 1][j + 1] = 1;
}

void solve(int n, int m, int **A) {
    vector<pair<int, int >> result;

    //pack
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m -1; ++j) {
            if (filter(A, i, j) == 4) {
                result.emplace_back(i, j);
            }
        }
    }

    //unpack
    int **unpacked_A = new int *[n];
    for (int i = 0; i < n; ++i) {
        unpacked_A[i] = new int[m]();
    }

    for (auto p: result) {
        fill(unpacked_A, p.first, p.second);
    }

    //check equal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] != unpacked_A[i][j]) {
                cout << -1;
                return;
            }
        }
    }

    //OK
    cout << result.size() << endl;
    for (auto p: result) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, m;
    cin >> n >> m;

    int **A = new int *[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    solve(n, m, A);

    return 0;
}