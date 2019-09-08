//
// Created by 10578 on 8/28/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream _in(filename); cin.rdbuf(_in.rdbuf());
#define LOCAL

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Tree {
public:
    TreeNode *root;

    Tree(vector<int> nums) {
        /**
         * Build a binary tree from level traversal.
         */
        root = new TreeNode(nums[0]);
        queue<TreeNode *> q({root});

        TreeNode *node, *new_node;
        for (int i = 1; i < (int) nums.size(); ++i) {
            node = q.front();
            new_node = new TreeNode(nums[i]);

            if (node->left == nullptr) {
                node->left = new_node;
            } else if (node->right == nullptr) {
                node->right = new_node;
                q.pop();
            }

            q.push(new_node);
        }
    }
};

class Solution {
public:
    vector<string> strs;

    int sumRootToLeaf(TreeNode *root) {
        if (!root) {
            return 0;
        }

        cal_str(root, "");
        int sum = 0;
        for (auto &s: strs) {
            sum += stol(s, nullptr, 2);
        }

        return sum;
    }

    void cal_str(TreeNode *root, const string &str) {
        string this_str = str + (root->val == 1 ? '1' : '0');

        if (root->left == nullptr && root->right == nullptr) { //leaf
            strs.push_back(this_str);
            return;
        }

        if (root->left)
            cal_str(root->left, this_str);

        if (root->right)
            cal_str(root->right, this_str);
    }
};

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> nums;

    string line;
    getline(cin, line);
    istringstream ist(line);
    for (int temp; ist >> temp;) {
        nums.push_back(temp);
    }
    Tree tree(nums);

    Solution s;
    int result = s.sumRootToLeaf(tree.root);
    cout << result;
}