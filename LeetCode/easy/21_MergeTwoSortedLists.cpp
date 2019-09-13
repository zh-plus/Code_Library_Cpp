//
// Created by 10578 on 8/28/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>

#define BOOST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ALTER_IN(name) fstream _in(name); cin.rdbuf(_in.rdbuf());
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto *root = new ListNode(-1);
        ListNode *tail = root;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return root->next;
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

    vector<int> num1, num2;
    num1.reserve(100);
    num2.reserve(100);

    string line;
    getline(cin, line);
    istringstream ist(line);
    for (int temp; ist >> temp;) {
        num1.push_back(temp);
    }

    getline(cin, line);
    ist.clear();
    ist.str(line);
    for (int temp; ist >> temp;) {
        num2.push_back(temp);
    }

    ListNode *l1 = vector2list(num1), *l2 = vector2list(num2);

    Solution s;
    ListNode *result = s.mergeTwoLists(l1, l2);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

}