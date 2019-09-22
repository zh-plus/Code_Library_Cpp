//
// Created by 10578 on 2019/9/22.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

__attribute__ ((constructor))
void myStartupFun(){
    BOOST_IO;
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size() + 1][word2.size() + 1];
        for (int i = 0, sz = word1.size() + 1; i < sz; ++i) {
            dp[i][0] = i;
        }

        for (int j = 0, sz = word2.size() + 1; j < sz; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1, sz1 = word1.size() + 1; i < sz1; ++i) {
            for (int j = 1, sz2 = word2.size() + 1; j < sz2; ++j) {
                dp[i][j] = word1[i - 1] == word2[j - 1] ?
                           dp[i - 1][j - 1] :
                           min({dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1});
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    string word1, word2;
    cin >> word1 >> word2;

    cout << Solution().minDistance(word1, word2);

    return 0;
}