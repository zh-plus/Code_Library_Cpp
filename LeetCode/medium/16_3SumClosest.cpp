//
// Created by 10578 on 9/12/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream in(name); cin.rdbuf(in.rdbuf());
#define LOCAL

using namespace std;

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int p, q, sum, closest = INT32_MAX, min_distance = INT32_MAX;
        for (int i = 0, end = nums.size() - 2; i < end; ++i) {
            p = i + 1, q = end + 1;

            while (p < q) {
                sum = nums[i] + nums[p] + nums[q];
                if (sum == target) {
                    return sum;
                }

                if (int distance = abs(sum - target); distance < min_distance) {
                    min_distance = distance;
                    closest = sum;
                }

                sum < target ? p++ : q--;
            }
        }

        return closest;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> nums;
    int target;

    string line;
    getline(cin, line);
    istringstream ist(line);
    for (int temp; ist >> temp;) {
        nums.push_back(temp);
    }
    cin >> target;

    Solution s;
    cout << s.threeSumClosest(nums, target);
}
