//
// Created by 10578 on 2021/3/10.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "sstream"
#include "iterator"
#include "deque"


#define ALTER_IN(filename) std::f_stream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;

__attribute__ ((constructor))
void my_startup_fn(){
    BOOST_IO;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution{
public:
    TreeNode* addOneRow(TreeNode *root, int v, int d){
        if (d == 1) {
            TreeNode *new_node = new TreeNode(v);
            new_node->left = root;

            return new_node;
        }

        vector<TreeNode *> nodes;

        //Layer Traverse to d-1
        deque<TreeNode *> q;
        q.push_back(root);
        int cur = 0, last = 1;
        int level = 1;
        TreeNode *temp;

        while (level < d - 1) {
            cur = 0;
            last = q.size();

            while (cur < last) {
                temp = q.front();
                q.pop_front();

                if (TreeNode* left = temp->left) {
                    q.push_back(left);
                }

                if (TreeNode *right = temp->right) {
                    q.push_back(right);
                }

                ++cur;
            }

            ++level;
        }

        TreeNode *origin_left, *origin_right;
        for (auto *node: q) {
            origin_left = node->left;
            origin_right = node->right;

            node->left = new TreeNode(v, origin_left, nullptr);
            node->right = new TreeNode(v, nullptr, origin_right);
        }

        return root;
    }
};