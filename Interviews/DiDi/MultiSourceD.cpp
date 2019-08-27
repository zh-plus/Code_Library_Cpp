//
// Created by 10578 on 8/27/2019.
//

//#define LOCAL

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

#define LOCAL

using namespace std;

class TreeNode{
public:

    vector<TreeNode> children;
    int value;
    TreeNode *parent;

    explicit TreeNode(): children{}, value{0}, parent{} {};

    explicit TreeNode(int v) : children{}, value{v}, parent{} {};

    void add_child(TreeNode &child){
        children.push_back(child);
        child.parent = this;
    }
};

class Tree{
public:
    vector<TreeNode> nodes;
    vector<vector<int>> levels;

    explicit Tree(int n){
        nodes.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            nodes[i] = TreeNode(i);
        }

        levels.resize(n);
        for (int i = 0; i < n; ++i) {
            levels[i] = vector<int>();
        }
    }

    void choose_parent(int child, int parent){
        nodes[parent].add_child(nodes[child]);
    }

    TreeNode get_root(){
        TreeNode root = nodes[1];
        while (root.parent) {
            root = *root.parent;
        }

        return root;
    }

    void cal_levels(){
        TreeNode root = get_root();
        levels[0].push_back(root.value);
        for (const TreeNode& c: root.children) {
            dfs(c, 1);
        }
    }

    void dfs(const TreeNode& node, int level_num) {
        levels[level_num].push_back(node.value);
        int next_level = level_num + 1;
        for (const TreeNode& c: node.children) {
            dfs(c, next_level);
        }
    }

    int get_level(int num) {
        for (int i = 0; i < (int)levels.size(); ++i) {
            for (int value: levels[i]) {
                if (value == num) {
                    return i;
                }
            }
        }

        return -1;
    }
};


int solve(int n, int m, int d, vector<int> M, vector<int> P) {
    Tree tree(n);

    for (int i = 1; i <= n - 1; ++i) {
        tree.choose_parent(i + 1, P[i - 1]);
    }

    tree.cal_levels();
    unordered_set<int> valid_levels;
    int upper, lower, level;
    for (auto value: M) {
        level = tree.get_level(value);
        upper = min(level + d, n - 1);
        lower = max(level - d, 0);

        for (int i = lower; i <= upper; ++i) {
            valid_levels.insert(i);
        }
    }

    int result = 0;
    for (auto l: valid_levels) {
        result += tree.levels[l].size();
    }

    return result;
}

int main() {

#ifdef LOCAL
    ifstream in("./in.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, m, d;
    cin >> n >> m >> d;

    vector<int> M(m);
    for (int i = 0; i < m; ++i) {
        cin >> M[i];
    }

    vector<int> P(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> P[i];
    }

    int result = solve(n, m, d, M, P);
    cout << result;
}