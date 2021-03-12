//
// Created by 10578 on 2021/3/12.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"
#include "sstream"
#include "fstream"
#include "iterator"
#include "string"
#include "limits"

#define ALTER_IN(filename) std::fstream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

#ifdef __GUNG__
__attribute__((constructor))
void my_startup_fn(){
    BOOST_IO;
}
#endif

using namespace std;

class Solution {
public:
    static int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;

        for (int i = 1; i < dp.size(); ++i) {
            for (auto &&item: coins) {
                if (item <= i && dp[i - item] != numeric_limits<int>::max()) {
                    dp[i] = min(dp[i], dp[i - item] + 1);
                }
            }
        }

        return dp.back() == numeric_limits<int>::max() ? -1 : dp.back();
    }
};

int main() {
    ALTER_IN("in.txt");

    int T;
    cin >> T;

    Solution s;
    string line;
    int amount;
    while (T--) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, line);
        stringstream ss(line);
        istream_iterator<int> start(ss), end;

        vector<int> coins(start, end);
        cin >> amount;

        cout << (Solution::coinChange(coins, amount)) << endl;
    }

    return 0;
}
