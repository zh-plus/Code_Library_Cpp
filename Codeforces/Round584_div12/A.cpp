//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;

int solve(vector<int> nums){
    int result = 0;

    sort(nums.begin(), nums.end());
    unordered_set<int> uncorlored(nums.begin(), nums.end());

    for (int i = 0, sz = nums.size(); i < sz; ++i) {
        if (uncorlored.find(nums[i]) == uncorlored.end()) {
            continue;
        }

        result++;
        for (int j = i; j < sz; ++j) {
            if (uncorlored.find(nums[j]) != uncorlored.end() && nums[j] % nums[i] == 0) {
                uncorlored.erase(nums[j]);
            }
        }

        if (uncorlored.empty()){
            break;
        }
    }

    return result;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = solve(nums);
    cout << result;

    return 0;
}