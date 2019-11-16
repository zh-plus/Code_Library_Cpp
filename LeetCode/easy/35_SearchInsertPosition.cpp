//
// Created by 10578 on 10/21/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        int index = distance(nums.begin(), ub);
        if (int former = index - 1; former >= 0 && nums[former] == target) {
            return former;
        } else {
            return index;
        }
    }
};


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> nums;
    nums.reserve(100);
    int target;

    string line;
    getline(cin, line);
    istringstream ist(line);
    for (int n; ist >> n;) {
        nums.push_back(n);
    }

    cin >> target;

    cout << Solution().searchInsert(nums, target);
}