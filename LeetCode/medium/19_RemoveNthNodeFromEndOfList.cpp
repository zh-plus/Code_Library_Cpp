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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *node = &dummy;

        queue<ListNode *> q;
        while (node) {
            q.push(node);

            if (q.size() > n + 1) {
                q.pop();
            }

            node = node->next;
        }

        ListNode *last = q.front();
        q.pop();
        ListNode *deleted = q.front();
        q.pop();
        deleted->next = nullptr;

        last->next = !q.empty() ? q.front() : nullptr;

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

    string line;
    getline(cin, line);
    istringstream ist(line);
    vector<int> nums;
    for (int num; ist >> num;) {
        nums.push_back(num);
    }
    ListNode *list = vector2list(nums);

    int n;
    cin >> n;

    ListNode *result = Solution().removeNthFromEnd(list, n);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
}
