//
// Created by 10578 on 2019/8/19.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

class Solution {
public:
    void sortColors1(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](auto x, auto y) { return y - x > 0; });
    }

    void sortColors(vector<int> &nums){
        vector<int> sorted_nums(nums.size());
        int p = 0, q = nums.size() - 1;
        for (auto x: nums) {
            switch (x) {
                case 0:
                    sorted_nums[p++] = x;
                    break;
                case 2:
                    sorted_nums[q--] = x;
                    break;
                default:
                    break;
            }
        }

        for (int i = p; i <= q; ++i) {
            sorted_nums[i] = 1;
        }

        nums = sorted_nums;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<int> nums;

    string line;

    getline(cin, line);
    istringstream ss(line);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    Solution s;
    s.sortColors(nums);
    for (auto x: nums) {
        cout << x << " ";
    }

    return 0;
}