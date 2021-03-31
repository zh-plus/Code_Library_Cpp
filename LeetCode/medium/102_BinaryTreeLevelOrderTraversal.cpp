//
// Created by 10578 on 2021/3/31.
//

#include "vector"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto result = vector<vector<int>>{};
        int level_num = 1, new_level_num;
        deque<TreeNode *> dq{};

        if (root) {
            dq.push_back(root);
        }

        while (!dq.empty()) {
            new_level_num = 0;
            result.emplace_back();
            while (level_num--){
                TreeNode *curr = dq.front();
                dq.pop_front();
                result.back().push_back(curr->val);

                if (curr->left) {
                    dq.push_back(curr->left);
                    ++new_level_num;
                }

                if (curr->right) {
                    dq.push_back(curr->right);
                    ++new_level_num;
                }
            }

            level_num = new_level_num;
        }

        return result;
    }
};