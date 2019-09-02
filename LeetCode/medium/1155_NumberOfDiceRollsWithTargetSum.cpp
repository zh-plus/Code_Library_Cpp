//
// Created by 10578 on 9/2/2019.
//

#include <iostream>
#include <fstream>
#include <vector>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream f_in(filename); cin.rdbuf(f_in.rdbuf());
#define LOCAL
#define MOD 1000000007

using namespace std;

class Solution {
public:
    int numRollsToTarget1(int d, int f, int target) {
        /**
         * 2d DP.
         * O(d * f * target) Time Complexity, O(d * target) Space Complexity
         */
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= d; ++i) {
            for (int j = 1; j <= target && j <= i * f; ++j) {
                for (int k = 1; k <= f && k <= j; ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }

        return dp[d][target];
    }

    int numRollsToTarget(int d, int f, int target) {
        /**
         * 1d DP.
         * O(d * f * target) Time Complexity, O(target) Space Complexity
         */
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= d; ++i) {
            for (int j = min(target, i * f); j >= 1; --j) {
                dp[j] = 0;
                for (int k = min(f, i == 1 ? j : j - 1); k >= 1; --k) {
                    dp[j] = (dp[j] + dp[j - k]) % MOD;
                }

                if (i == d)
                    break;
            }
        }

        return dp[target];
    }
};

static auto magic = []() { BOOST_IO; };

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int d, f, target;
    cin >> d >> f >> target;

    Solution s;
    cout << s.numRollsToTarget(d, f, target);

    return 0;
}