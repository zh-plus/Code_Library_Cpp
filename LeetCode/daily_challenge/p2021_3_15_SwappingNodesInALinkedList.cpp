//
// Created by 10578 on 2021/3/15.
//

#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"
#include "iterator"
#include "stack"
#include "initializer_list"


#define ALTER_IN(filename) std::f_stream in_f(filename); std::cin.rdbuf(in_f.rdbuf());
#define BOOST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);


using namespace std;

//struct ListNode {
//    int val;
//    ListNode *next;
//
//    ListNode() : val(0), next(nullptr) {}
//
//    explicit ListNode(int x) : val(x), next(nullptr) {}
//
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//
//    explicit ListNode(initializer_list<int> list) {
//        auto temp = this;
//        if (list.size() == 0) {
//            return;
//        }
//        temp->val = *begin(list);
//
//        for (auto iter = begin(list) + 1; iter != end(list); ++iter) {
//            temp->next = new ListNode();
//            temp = temp->next;
//            temp->val = *iter;
//        }
//    }
//
//    void print(){
//        auto *temp = this;
//        while (temp) {
//            cout << temp->val << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//};


class Solution {
public:
    static ListNode *swapNodes(ListNode *head, int k) {
        stack<ListNode *> s;

        ListNode *left_k = nullptr, *right_k = nullptr;
        ListNode *temp = head;

        int i = 1;
        while (temp) {
            s.push(temp);

            if (i == k) {
                left_k = temp;
            }

            temp = temp->next;
            ++i;
        }

        i = 1;
        while (!s.empty()) {
            temp = s.top();
            s.pop();

            if (i == k) {
                right_k = temp;
                break;
            }

            ++i;
        }

        if (left_k && right_k) {
            swap(left_k->val, right_k->val);
        }

        return head;
    }
};

int main() {
    auto *test_list = new ListNode{1, 2, 3, 4, 5};
    auto new_head = Solution::swapNodes(test_list, 4);

    new_head->print();

    return 0;
}