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
    /**
     * Brute force, O(mn) space complexity.
     * @param matrix
     */
    void setZeroes1(vector<vector<int>> &matrix) {
        int h = matrix.size();
        if (!h) {
            return;
        }

        int w = matrix[0].size();

        bool *zero_row = new bool[h]();
        bool *zero_col = new bool[w]();

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!matrix[i][j]) {
                    zero_row[i] = true;
                    zero_col[j] = true;
                }
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (zero_row[i] || zero_col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    /**
     * Optimal, O(1) space complexity.
     * @param matrix
     */
    void setZeroes(vector<vector<int>> &matrix) {
        int h = matrix.size();
        if (!h) {
            return;
        }

        int w = matrix[0].size();

        bool row1_zero = false, col1_zero = false;
        for (int j = 0; j < w; ++j) {
            if (not matrix[0][j]) {
                row1_zero = true;
                break;
            }
        }

        for (int i = 0; i < h; ++i) {
            if (not matrix[i][0]) {
                col1_zero = true;
                break;
            }
        }

        for (int i = 1; i < h; ++i) {
            for (int j = 1; j < w; ++j) {
                if (not matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int j = 1; j < w; ++j) {
            if (not matrix[0][j]) {
                for (int i = 1; i < h; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < h; ++i) {
            if (not matrix[i][0]) {
                for (int j = 1; j < w; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (row1_zero) {
            for (int j = 0; j < w; ++j) {
                matrix[0][j] = 0;
            }
        }

        if (col1_zero) {
            for (int i = 0; i < h; ++i) {
                matrix[i][0] = 0;
            }
        }
    }

};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<vector<int>> matrix;

    string line;

    while (getline(cin, line)) {
        vector<int> row;

        istringstream ss(line);
        int num;
        while (ss >> num) {
            row.push_back(num);
        }

        matrix.push_back(row);
    }

    Solution s;
    s.setZeroes(matrix);
    for (const auto &r: matrix) {
        for (const auto &x: r) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}