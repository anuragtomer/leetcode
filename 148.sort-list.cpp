#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    ListNode *split(ListNode *head, int n) {
        for (int i = 1; head && i < n; ++i) {
            head = head->next;
        }
        if (!head)
            return head;
        ListNode *nextList = head->next;
        head->next = nullptr;
        return nextList;
    }
    ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head) {
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        head->next = l1 ? l1 : l2;
        while (head && head->next)
            head = head->next;
        return head;
    }

   public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        int len = 0;
        ListNode *curr = head;
        while (curr) {
            ++len;
            curr = curr->next;
        }
        ListNode *left, *right, *tail;
        ListNode dummy = ListNode();
        dummy.next = head;
        for (int i = 1; i < len; i *= 2) {
            curr = dummy.next;
            tail = &dummy;
            while (curr) {
                left = curr;
                right = split(left, i);
                curr = split(right, i);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution sol;

    return 0;
}

