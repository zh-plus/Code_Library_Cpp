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
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty() || intervals.size() == 1) {
            return vector<vector<int>>{intervals};
        }

        sort(intervals.begin(), intervals.end(), [](const auto &x, const auto &y) { return x[0] < y[0]; });

        vector<vector<int>> result;

        auto temp_interval = intervals[0];
        for (auto &interval: intervals) {
            if (interval[0] <= temp_interval[1]) {
                temp_interval[1] = max(temp_interval[1], interval[1]);
            } else {
                result.emplace_back(temp_interval);
                temp_interval = interval;
            }
        }

        if (result.empty() or result[result.size() - 1][1] < temp_interval[0]) {
            result.push_back(temp_interval);
        }

        return result;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<vector<int>> intervals;
    int a, b;
    while (cin >> a >> b) {
        intervals.push_back(vector<int>{a, b});
    }

    Solution s;
    auto result = s.merge(intervals);
    for (auto r: result) {
        cout << r[0] << " " << r[1] << endl;
    }

    return 0;
}