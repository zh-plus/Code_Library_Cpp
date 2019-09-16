//
// Created by 10578 on 9/1/2019.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(filename) fstream fin(filename); cin.rdbuf(fin.rdbuf());
#define LOCAL

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {};
};

__attribute__ ((constructor))
void myStartupFun() {
    BOOST_IO;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;

        auto cmp = [](ListNode* a, ListNode *b) {return a->val > b->val;};
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        for (auto &l: lists)
            if (l)
                pq.push(l);

        ListNode *node;
        while (!pq.empty()) {
            node = pq.top();
            pq.pop();

            tail->next = new ListNode(node->val);
            tail = tail->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};

ListNode *vector2list(vector<int> &num) {
    auto *root = new ListNode(-1);
    ListNode *last = root;

    for (auto &x: num) {
        last->next = new ListNode(x);
        last = last->next;
    }

    return root->next;
}

int main() {
    BOOST_IO;

#ifdef LOCAL
    ALTER_IN("in.txt");
#endif

    vector<ListNode*> lists;
    string line;
    istringstream ist;
    while (getline(cin, line)) {
        ist.clear();
        ist.str(line);

        vector<int> nums;
        for (int num; ist >> num;) {
            nums.push_back(num);
        }

        lists.push_back(vector2list(nums));
    }

    Solution solution;
    ListNode *result = solution.mergeKLists(lists);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
}
