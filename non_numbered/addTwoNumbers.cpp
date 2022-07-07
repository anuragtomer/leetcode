#include "lib.h"

class Solution {
public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
        ListNode * l3 = NULL;
        ListNode * temp = NULL;
        int carry = 0;
        while (l1 && l2) {
            int val = l1->val + l2->val + carry;
            if (val > 9) {
                carry = 1;
                val = val % 10;
            } else
                carry = 0;
            if (!l3) {
                l3 = new ListNode(val);
                temp = l3;
            } else {
                temp->next = new ListNode(val);
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int val = l1->val + carry;
            if (val > 9) {
                carry = 1;
                val = val % 10;
            } else
                carry = 0;
            if (!l3) {
                l3 = new ListNode(val);
                temp = l3;
            } else {
                temp->next = new ListNode(val);
                temp = temp->next;
            }
            l1 = l1->next;
        }
        while(l2) {
            int val = l2->val + carry;
            if (val > 9) {
                carry = 1;
                val = val % 10;
            } else
                carry = 0;
            if (!l3) {
                l3 = new ListNode(val);
                temp = l3;
            } else {
                temp->next = new ListNode(val);
                temp = temp->next;
            }
            l2 = l2->next;
        }
        if (carry) {
            if (!l3) {
                l3 = new ListNode(carry);
                temp = l3;
            } else {
                temp->next = new ListNode(carry);
                temp = temp->next;
            }
        }
        return l3;
    }
};

int main(){
    Solution sol;
    ListNode *l1 = createList();
    ListNode * l2 = createList();
    ListNode * l3 = sol.addTwoNumbers(l1, l2);
    printListNode(l3);
    return 0;
}
