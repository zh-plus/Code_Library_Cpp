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
    ll uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        /**
        * Dynamic programming.
        */

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<ll>> dp(m, vector<ll>(n, 0));
        dp.back().back() = obstacleGrid.back().back() ? 0 : 1;

        for (int j = n - 2; j >= 0; --j) {
            dp.back()[j] = obstacleGrid.back()[j] || !dp.back()[j + 1] ? 0 : 1;
        }

        for (int i = m - 2; i >= 0; --i) {
            dp[i].back() = obstacleGrid[i].back() || !dp[i + 1].back() ? 0 : 1;
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
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
    cout << solution.uniquePathsWithObstacles(obstacles);

    return 0;
}