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
    ListNode *getMidPoint(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (fast)
            fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *current = head, *prev = nullptr, *next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    bool areTheySame(ListNode *list1, ListNode *list2) {
        while (list1 && list2) {
            if (list1->val != list2->val)
                return false;
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }

   public:
    bool isPalindrom(ListNode *head) {
        auto midPoint = getMidPoint(head);
        auto reverseHead = reverse(midPoint);
        return areTheySame(head, reverseHead);
    }
};

int main() {
    Solution sol;

    return 0;
}

