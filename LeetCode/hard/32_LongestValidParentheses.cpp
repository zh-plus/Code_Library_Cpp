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
    int longestValidParentheses(string s) {
        int result = 0;
        s = ')' + s;
        vector<int> dp(s.size(), 0);
        for (int i = 2, sz = s.size(); i < sz; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = dp[i - 2] + 2;
                } else if (s[i - 1 - dp[i - 1]] == '(') {
                    dp[i] = dp[i - 1] + 2 + (i - 2 - dp[i - 1] >= 0 ? dp[i - 2 - dp[i - 1]] : 0);
                }
                result = max(result, dp[i]);
            }
        }

        return result;
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

    string s;
    cin >> s;
    cout << Solution().longestValidParentheses(s);
}
