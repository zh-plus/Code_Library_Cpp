//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

string solve(int n, vector<int> nums) {
    unordered_set<int> colored1;
    unordered_set<int> colored2;
    int value, index;

    int i = 0;
    int color2_start = 1;
    colored1.insert(i);
    while (i < n) {
        index = n;
        value = INT32_MAX;

        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < value && nums[j] >= nums[i]) {
                value = nums[j];
                index = j;
            }
        }
        if (index != n)
            colored1.insert(index);

        if (index == color2_start)
            color2_start = index + 1;

        i = index;
    }

    if (color2_start < n) {
        i = color2_start;
        colored2.insert(i);
        while (i < n) {
            if (colored1.find(i) != colored1.end()) {
                ++i;
                continue;
            }

            index = n;
            value = INT32_MAX;

            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < value && nums[j] >= nums[i]
                    && colored1.find(j) == colored1.end()) {
                    value = nums[j];
                    index = j;
                }
            }

            if (index != n)
                colored2.insert(index);

            i = index;
        }
    }

    if (colored1.size() + colored2.size() != n) {
        return "-";
    } else {
        if (colored2.empty()) {
            return string(n, '1');
        }

        int min1 = INT32_MAX, min2= INT32_MAX, max1= INT32_MIN, max2 = INT32_MIN;
        for (auto &x: colored1) {
            min1 = min(min1, nums[x]);
            max1 = max(max1, nums[x]);
        }

        for (auto &x: colored2) {
            min2 = min(min2, nums[x]);
            max2 = max(max2, nums[x]);
        }

        if (max1 <= min2) {
            string result(n, '1');
            for (auto &c: colored2) {
                result[c] = '2';
            }

            return result;
        } else if (max2 <= min1) {
            string result(n, '2');
            for (auto &c: colored2) {
                result[c] = '1';
            }

            return result;
        } else {
            return "-";
        }
    }
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int t;
    cin >> t;

    int n;
    string digits;
    string result;
    vector<int> nums;
    while (t--) {
        cin >> n;
        nums.resize(n);

        cin >> digits;
        for (int i = 0; i < n; ++i) {
            nums[i] = digits[i] - '0';
        }

        result = solve(n, nums);
        cout << result << endl;
    }
}