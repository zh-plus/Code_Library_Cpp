//
// Created by 10578 on 2019/8/19.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stack>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

__attribute__ ((constructor))
void myStartupFun(){
    BOOST_IO;
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        /**
         * O(m * n)
         */

        if (matrix.empty()) {
            return 0;
        }

        vector<vector<int>> histograms(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int j = 0, sz2 = matrix[0].size(); j < sz2; ++j) {
            histograms[0][j] = matrix[0][j] - '0';
        }

        for (int i = 1, sz1 = matrix.size(); i < sz1; ++i) {
            for (int j = 0, sz2 = matrix[0].size(); j < sz2; ++j) {
                histograms[i][j] = (matrix[i][j] == '1') ? 1 + histograms[i - 1][j] : 0;
            }
        }

        int result = 0;
        for (auto h: histograms) {
            result = max(result, maxAreaInHistogram(h));
        }

        return result;
    }

    int maxAreaInHistogram(vector<int> &histogram) {
        /**
         * O(n)
         */

        int result = 0;
        stack<int> s;
        histogram.push_back(0);

        int n = histogram.size();
        int i = 0, left = 0, right = 0, height;
        while (i < n) {
            if (s.empty() || histogram[i] > histogram[s.top()]) {
                s.push(i);
                i++;
            } else {
                height = histogram[s.top()];
                s.pop();
                left = s.empty() ? -1 : s.top();
                right = i;
                result = max(result, height * (right - left - 1));
            }
        }

        histogram.pop_back();

        return result;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<vector<char>> matrix;
    string line;
    istringstream ist;
    vector<char> temp;
    while (getline(cin, line)) {
        ist.clear();
        ist.str(line);
        temp.clear();

        for (char c; ist >> c;) {
            temp.push_back(c);
        }

        matrix.push_back(temp);
    }

    cout << Solution().maximalRectangle(matrix);

    return 0;
}