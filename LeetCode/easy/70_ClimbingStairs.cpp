//
// Created by 10578 on 8/28/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

__attribute__ ((constructor))
void myStartupFun(){
    BOOST_IO;
}

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }

        vector<int> fibonacci(n);
        fibonacci[0] = 1;
        fibonacci[1] = 2;

        for (int i = 2; i < n; ++i) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }

        return fibonacci[n - 1];
    }
};


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int n;
    cin >> n;

    Solution s;
    cout << s.climbStairs(n);
}