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
#define ALTER_IN(file_name) fstream in_f(file_name); cin.rdbuf(in_f.rdbuf());

using namespace std;

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return  -1;
        }

        int lo = 0, hi = nums.size() - 1;
        int mid;
        while (lo < hi) {
            mid = (hi - lo) / 2 + lo;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        int sep = lo;
        hi = nums.size() - 1;
        while (lo < hi) {
            mid = (hi - lo) / 2 + lo;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (nums[lo] == target) {
            return lo;
        }

        lo = 0;
        hi = sep - 1;
        while (lo < hi) {
            mid = (hi - lo) / 2 + lo;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (nums[lo] == target) {
            return lo;
        } else {
            return -1;
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
    string line;
    getline(cin, line);
    istringstream ist(line);
    for (int n; ist >> n;){
        nums.push_back(n);
    }

    int target = 5;
    cin >> target;

    cout << Solution().search(nums, target);

    return 0;
}