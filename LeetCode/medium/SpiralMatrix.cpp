//
// Created by 10578 on 8/26/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

class Solution {
public:
    vector<int> result;

    void recursive(vector<vector<int>> &matrix, int l, int r, int up, int down) {
        //upper
        for (int j = l; j <= r; ++j) {
            result.push_back(matrix[up][j]);
        }

        //right
        for (int i = up + 1; i <= down; ++i) {
            result.push_back(matrix[i][r]);
        }

        if (up != down) {
            //lower
            for (int j = r - 1; j >= l; --j) {
                result.push_back(matrix[down][j]);
            }
        }

        if (l != r) {
            //left
            for (int i = down - 1; i > up; --i) {
                result.push_back(matrix[i][l]);
            }
        }

        l++;
        r--;
        down--;
        up++;
        if (l <= r && up <= down) {
            recursive(matrix, l, r, up, down);
        }
    }

    vector<int> spiralOrder(vector<vector<int>> matrix) {
        if (matrix.empty()) {
            return vector<int>{};
        }

        recursive(matrix, 0, matrix[0].size() - 1, 0, matrix.size() - 1);

        return result;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    fstream in("in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<vector<int>> matrix;

    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> temp;
        int num;
        while (iss >> num) {
            temp.push_back(num);
        }

        matrix.push_back(temp);
    }

    Solution s;
    auto results = s.spiralOrder(matrix);
    for (auto r: results) {
        cout << r << " ";
    }
}