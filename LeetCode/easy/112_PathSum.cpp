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
void myStartupFun() {
    BOOST_IO;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (not root) {
            return false;
        } else if (root->val == sum && not root->left && not root->right) {
            return true;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

    bool result = false;
    int sum = 0;

    void back_track(TreeNode *node, int value) {
        if (result) {
            return;
        }

        value += node->val;

        if (node->left == nullptr && node->right == nullptr) {
            result = value == sum;
            return;
        }

        if (TreeNode *next = node->left) {
            back_track(next, value);
        }

        if (TreeNode *next = node->right) {
            back_track(next, value);
        }
    }

    bool hasPathSum1(TreeNode *root, int sum) {
        this->sum = sum;

        back_track(root, 0);

        return result;
    }
};

int main() {
    BOOST_IO;

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    return 0;
}