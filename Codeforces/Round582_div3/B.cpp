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

int solve(int n, const vector<int> &nums) {
    int count = 0;
    int min = nums.back();
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] > min) {
            count++;
        } else if (nums[i] < min) {
            min = nums[i];
        }
    }

    return count;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> nums;
    int t, n, temp, result;
    cin >> t;
    while (t--) {
        nums.clear();
        cin >> n;
        while (n--) {
            cin >> temp;
            nums.push_back(temp);
        }

        result = solve(n, nums);
        cout << result << endl;
    }

    return 0;
}