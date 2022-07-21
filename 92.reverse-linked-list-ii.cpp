/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  ListNode *reverseLength(ListNode *head, int length) {
    if (head == nullptr || length <= 0)
      return head;
    ListNode *curr = head, *next = nullptr, *prev = nullptr;
    while (curr && length > 0) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      --length;
    }
    head->next = curr;
    return prev;
  }

 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *temp = head;
    int length = right - left + 1;
    --left;
    if (left == 0)
      return reverseLength(head, length);
    while (temp && left - 1 > 0) {
      temp = temp->next;
      --left;
    }
    temp->next = reverseLength(temp->next, length);
    return head;
  }
};
