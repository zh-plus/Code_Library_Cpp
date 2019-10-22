//
// Created by 10578 on 2019/8/30.
//

#include <vector>
#include <iostream>
#include <fstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
//#define LOCAL

using namespace std;


vector<int> solve(int n, vector<int> nums) {
    nums.insert(nums.begin(), 0);
    vector<bool> visited(nums.size(), false);
    vector<int> result(nums.size(), 1);
    vector<int> cycle_nums;

    for (int i = 1, sz = nums.size(); i < sz; ++i) {
        if (visited[i]) {
            continue;
        } else {
            visited[i] = true;
        }

        cycle_nums.clear();
        cycle_nums.push_back(i);
        int j = i;
        int days = 1;

        while (nums[j] != i) {
            ++days;
            j = nums[j];
            cycle_nums.push_back(j);
            visited[j] = true;
        }

        for (const auto &x: cycle_nums) {
            result[x] = days;
        }
    }

    result.erase(result.begin());
    return result;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        for (const auto &x: solve(n, nums)) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}