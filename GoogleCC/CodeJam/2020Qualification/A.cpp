//
// Created by 10578 on 4/4/2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <set>
#include <tuple>
#include <utility>

//#define DEBUG

#define ALTER_IN(filename) std::fstream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;

auto solve(const vector<vector<int>> &matrix) {
    int trace = 0, rows = 0, cols = 0;
    int N = matrix.size();
    for (int i = 0; i < N; ++i) {
        trace += matrix[i][i];
    }

    for (auto &&v: matrix) {
        if (set<int>(v.begin(), v.end()).size() != N) {
            ++rows;
        }
    }

    set<int> temp_set;
    for (int j = 0; j < N; ++j) {
        temp_set.clear();
        for (int i = 0; i < N; ++i) {
            temp_set.insert(matrix[i][j]);
        }

        if (temp_set.size() != N) {
            ++cols;
        }
    }

    return make_tuple(trace, rows, cols);
}

int main() {
    BOOST_IO;

#ifdef DEBUG
    ALTER_IN("../in.txt");
#endif

    int T, N;
    int trace, rows, cols;
    cin >> T;

    vector<vector<int>> M;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        M.resize(N);

        for(auto &v: M) {
            vector<int> temp(N);
            copy_n(istream_iterator<int>(cin), N, temp.begin());

            v = move(temp);
        }

        tie(trace, rows, cols) = solve(M);
        cout << "Case #" << i << ": " << trace << " " << rows << " " << cols << endl;
    }

    return 0;
}
