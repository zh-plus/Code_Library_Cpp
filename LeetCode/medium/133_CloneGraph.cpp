//
// Created by 10578 on 9/10/2019.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream in_f(filename); cin.rdbuf(in_f.rdbuf());
#define LOCAL

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        Node *cur = node, *new_last = nullptr;
        unordered_map<Node *, Node *> copy_map;
        copy_map[cur] = new Node(node->val, {});

        stack<Node *> s;
        s.push(node);
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            new_last = copy_map[cur];

            for (auto &n: cur->neighbors) {
                if (copy_map.find(n) == copy_map.end()) {
                    copy_map[n] = new Node(n->val, {});
                    s.push(n);
                }

                new_last->neighbors.push_back(copy_map[n]);
            }
        }

        return copy_map[node];
    }
};

__attribute__ ((constructor))
void myStartupFun(){
    BOOST_IO;
}


int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    /*
     * No proper self-defined input main function.
     */

//    string line;
//    istringstream ist;
//    while (getline(cin, line)) {
//        ist.clear();
//        ist.str(line);

//    }

    return 0;
}