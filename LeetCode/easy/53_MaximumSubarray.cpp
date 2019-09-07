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

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        // Kadane's Algorithm
        int global_max = INT_MIN, max_ending_here = 0;
        for (int &num: nums) {
            max_ending_here += num;
            global_max = max(global_max, max_ending_here);

            if (max_ending_here < 0) {  // Change the determination position to allow negative result
                max_ending_here = 0;
            }
        }

        return global_max;
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

    vector<int> nums;
    nums.reserve(100);

    string line;
    getline(cin, line);
    istringstream ist(line);
    int temp;
    while (ist >> temp) {
        nums.push_back(temp);
    }

    Solution s;
    int result = s.maxSubArray(nums);
    cout << result;
}