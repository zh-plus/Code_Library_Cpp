//
// Created by 10578 on 2019/10/22.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define LOCAL

using namespace std;

__attribute__ ((constructor))
void myStartupFun(){
    BOOST_IO;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_check[9][9]{{false}};
        bool col_check[9][9]{{false}};
        bool block_check[9][9]{{false}};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int block_num = i / 3 * 3 + j / 3;
                int index = board[i][j] - '0' - 1;
                if (!row_check[i][index] && !col_check[j][index] && !block_check[block_num][index]) {
                    row_check[i][index] = true;
                    col_check[j][index] = true;
                    block_check[block_num][index] = true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (Solution().isValidSudoku(board) ? "true" : "false") << endl;

    return 0;
}