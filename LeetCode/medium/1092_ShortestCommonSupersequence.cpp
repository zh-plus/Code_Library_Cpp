//
// Created by 10578 on 9/2/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <numeric>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream f_in(filename); cin.rdbuf(f_in.rdbuf());
#define LOCAL

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1, sz1 = dp.size(); i < sz1; ++i) {
            for (int j = 1, sz2 = dp[0].size(); j < sz2; ++j) {
                dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp.back().back();
    }
};

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    string text1, text2;
    getline(cin, text1);
    getline(cin, text2);

    Solution solution;
    cout << solution.longestCommonSubsequence(text1, text2);
}