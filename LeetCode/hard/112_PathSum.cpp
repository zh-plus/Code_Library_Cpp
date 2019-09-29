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
    bool hasPathSum(TreeNode* root, int sum) {

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