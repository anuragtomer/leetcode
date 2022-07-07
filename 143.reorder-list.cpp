#include <cassert>
#include <iostream>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head, *prev = nullptr;
        while (curr) {
            auto nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

   public:
    void reorderList(ListNode **head) {
        ListNode *slow = *head, *fast = *head;
        if (!slow)
            return;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        // slow should be at mid now.
        fast = *head;
        while (fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        slow = reverse(slow);
        fast = *head;
        while (fast && slow) {
            auto temp = fast->next;
            fast->next = slow;
            auto temp2 = slow->next;
            slow->next = temp;
            fast = slow->next;
            slow = temp2;
        }
    }
};

int main() {
    Solution sol;
    ListNode *head = stringToList("1,2,3,4");
    ListNode *expected = stringToList("1,4,2,3");
    sol.reorderList(&head);
    assert(testList(head, expected));
    deleteList(head);
    deleteList(expected);
    head = stringToList("1,2,3,4,5");
    expected = stringToList("1,5,2,4,3");
    sol.reorderList(&head);
    assert(testList(head, expected));
    deleteList(head);
    deleteList(expected);
    return 0;
}
