//
// Created by 10578 on 9/1/2019.
//

#include <iostream>
#include <vector>
#include <fstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream fin(filename); cin.rdbuf(fin.rdbuf());
#define LOCAL

using namespace std;

class Solution {
public:
    bool isMatch1(string s, string p) {
        /**
         * Tricky pointer iteration O(sp) time, O(s + p) space algorithm.
         */
        const char *cs = s.c_str();
        const char *cp = p.c_str();

        const char *last_star = nullptr, *last_star_matched_next = nullptr;

        while (*cs) {
            if (*cs == *cp || *cp == '?') {
                cs++;
                cp++;
            } else if (*cp == '*') {
                last_star = cp;
                last_star_matched_next = cs; // Match nothing
                cp++;
            } else if (last_star) {
                cp = last_star + 1;
                cs = ++last_star_matched_next;
            } else {
                return false;
            }
        }

        while (*cp == '*') cp++;

        return !*cp;
    }

    bool isMatch(string s, string p) {
        /**
         * Original 2d dp approach.
         */

        int m = s.length() + 1, n = p.length() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));

        dp[0][0] = true;
        // No need to initialize dp[1:, 0] into false, because of the set value false

        for (int i = 1; i < n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?');
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

 __attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
    printf("BOOST_IO done!\n");
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    string s, p;
    getline(cin, s);
    getline(cin, p);

    Solution solution;
    bool result = solution.isMatch(s, p);

    cout << (result ? "true" : "false");

    return 0;
}
