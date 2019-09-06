//
// Created by 10578 on 9/2/2019.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    int get_size(TreeNode *node) {
        /**
         * Get the size of sub-tree rooting at node.
         */
        if (node == nullptr) {
            return 0;
        }

        int size = 0;
        stack<TreeNode *> s;
        s = stack<TreeNode *>({node});
        TreeNode *temp;
        while (!s.empty()) {
            temp = s.top();
            s.pop();
            size++;

            if (temp->left) {
                s.push(temp->left);
            }

            if (temp->right) {
                s.push(temp->right);
            }
        }

        return size;
    }

    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        TreeNode *node = nullptr, *opponent = nullptr;
        stack<TreeNode *> s({root});
        while (!s.empty()) {
            node = s.top();
            s.pop();

            if (node->val == x) {
                opponent = node;
                break;
            }

            if (node->left) {
                s.push(node->left);
            }

            if (node->right) {
                s.push(node->right);
            }
        }

        int left_sub = get_size(opponent->left);
        int right_sub = get_size(opponent->right);
        int p_sub = n - left_sub - right_sub - 1;
        vector<int> sub_tree{left_sub, right_sub, p_sub};

        return (*max_element(sub_tree.begin(), sub_tree.end()) > n / 2);
    }
};

 __attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
    printf("BOOST_IO done!\n");
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<int> nums;
    string line;
    getline(cin, line);
    istringstream iss(line);
    for (int num; iss >> num;) {
        nums.push_back(num);
    }

    int x;
    cin >> x;

    Tree treeNode(nums);
    Solution s;
    bool result = s.btreeGameWinningMove(treeNode.root, nums.size(), x);
    cout << (result ? "true" : "false");

    return 0;
}