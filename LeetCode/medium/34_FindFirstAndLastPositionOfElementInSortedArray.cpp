//
// Created by 10578 on 8/29/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL
#define ALTER_IN(name) fstream in(name); cin.rdbuf(in.rdbuf());

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }

        auto l = lower_bound(nums.begin(), nums.end(), target);
        if (l == nums.end() or *l != target) {
            return vector<int>{-1, -1};
        }

        auto r = upper_bound(l, nums.end(), target) - 1;
        int l_index = distance(nums.begin(), l), r_index = distance(nums.begin(), r);

        return vector<int>{l_index, r_index};
    }
};

static auto magic = []() { BOOST_IO };

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int num;
    vector<int> nums;
    string line;
    getline(cin, line);
    istringstream ist(line);
    while (ist >> num) {
        nums.push_back(num);
    }
    int target;
    cin >> target;

    Solution s;
    auto result = s.searchRange(nums, target);
    for (auto r: result) {
        cout << r << " ";
    }
}
