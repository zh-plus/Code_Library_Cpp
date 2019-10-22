//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

int solve(int n, vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1, sz = nums.size(); i < sz; ++i) {
        if (nums[i] - nums[i - 1] == 1){
            return 2;
        }
    }

    return 1;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        cout << solve(n, A) << endl;
    }

    return 0;
}