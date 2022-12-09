struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = l1 ? l1 : l2, *temp = nullptr;
    int carry = 0;
    while (l1 || l2 || carry) {
      if (l1 && l2) {
        if (!temp)
          temp = l1;
        else {
          temp->next = l1;
          temp = temp->next;
        }
        temp->val = l1->val + l2->val + carry;
        carry = temp->val / 10;
        temp->val = temp->val % 10;
      } else if (l1) {
        if (temp) {
          temp->next = l1;
          temp = temp->next;
        } else {
          temp = l1;
        }
        temp->val += carry;
        carry = temp->val / 10;
        temp->val = temp->val % 10;
      } else if (l2) {
        if (!temp) {
          temp = l2;
        } else {
          temp->next = l2;
          temp = temp->next;
        }
        temp->val += carry;
        carry = temp->val / 10;
        temp->val = temp->val % 10;
      } else {
        temp->next = new ListNode(carry);
        temp = temp->next;
        carry = temp->val / 10;
        temp->val = temp->val % 10;
      }
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return head;
  }
};
