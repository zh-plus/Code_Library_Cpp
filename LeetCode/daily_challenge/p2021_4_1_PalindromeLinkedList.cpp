//
// Created by 10578 on 2021/4/1.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "initializer_list"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode(std::initializer_list<int> ini) {
        ListNode *prev, *curr = this;
        for (auto &&x: ini) {
            curr->val = x;
            curr->next = new ListNode();
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
    }

    void print() {
        ListNode *curr = this;
        while (curr) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
    }
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head->next == nullptr) {
            return true;
        }

        //O(1) space complexity
        ListNode *mid = head, *tail = head;
        while (tail) {
            tail = tail->next;
            if (tail && tail->next) {
                mid = mid->next;
                tail = tail->next;
            }
        }

        ListNode *reversed_tail = mid->next;
        ListNode *curr = reversed_tail->next;
        reversed_tail->next = nullptr;
        ListNode *prev = reversed_tail;
        ListNode *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *reversed_head = prev;
        ListNode *rev_curr = reversed_head;
        ListNode *for_curr = head;
        while (rev_curr) {
            if (rev_curr->val != for_curr->val) {
                return false;
            }
            rev_curr = rev_curr->next;
            for_curr = for_curr->next;
        }

        return true;
    }
};

int main() {
    ListNode *head = new ListNode{1};

    Solution s;
    cout << s.isPalindrome(head);
}