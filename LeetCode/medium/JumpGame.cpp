//
// Created by 10578 on 8/24/2019.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

class Solution {
public:
    bool *cant;

    bool canJump(vector<int> &nums){
        int i = 0, max_num = nums[0];
        int last = nums.size() - 1;
        while (i <= max_num) {
            max_num = max(i + nums[i], max_num);
            if (i == last) {
                return true;
            }

            i++;
        }

        return false;
    }

    bool canJump1(vector<int> &nums) {
        cant = new bool[nums.size()]();

        bool result = dfs(nums, 0);

        return result;
    }

    bool dfs(vector<int> &nums, int start) {
        if (start >= nums.size()) {
            return false;
        }

        if (start == nums.size() - 1) {
            return true;
        }

        for (int i = min((int)nums.size() - 1 - start, nums[start]); i > 0; --i) {
            if (cant[start + i])
                continue;

            if (dfs(nums, start + i)) {
                return true;
            } else {
                cant[start + i] = true;
            }
        }

        return false;
    }
};


int main() {
    BOOST_IO;

#ifdef LOCAL
    fstream in("in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    string line;
    getline(cin, line);
    istringstream input(line);

    vector<int> nums;
    int num;
    while (input >> num) {
        nums.push_back(num);
    }

    Solution s;
    auto result = s.canJump(nums);

    cout << (result ? "true" : "false");
}