//
// Created by 10578 on 2019/8/19.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

typedef long long ll;

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(grid);
        for (int i = m - 2; i >= 0; --i) {
            dp[i].back() += dp[i + 1].back();
        }

        for (int i = n - 2; i >= 0; --i) {
            dp.back()[i] += dp.back()[i + 1];
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] += min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return *(*dp.begin()).begin();
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<vector<int>> obstacles;
    vector<int> row;
    obstacles.reserve(100);
    row.reserve(100);

    string line;
    istringstream ist;
    while (getline(cin, line)) {
        ist.clear();
        ist.str(line);
        row.clear();

        for (int num; ist >> num;) {
            row.push_back(num);
        }
        obstacles.push_back(row);
    }

    Solution solution;
    cout << solution.minPathSum(obstacles);

    return 0;
}