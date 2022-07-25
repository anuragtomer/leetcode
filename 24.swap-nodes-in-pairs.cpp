struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  ListNode *swap(ListNode *&head) {
    if (head && head->next) {
      ListNode *newHead = head->next;
      ListNode *next = newHead->next;
      newHead->next = head;
      head->next = next;
      return newHead;
    } else {
      return head;
    }
  }

 public:
  ListNode *swapPairs(ListNode *head) {
    head = swap(head);
    ListNode *temp = head ? head->next : nullptr;
    while (temp && temp->next) {
      temp->next = swap(temp->next);
      if (temp->next)
        temp = temp->next->next;
    }
    return head;
  }
};
