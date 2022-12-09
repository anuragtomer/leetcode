class Solution {
  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
  };

 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast) {
      fast = fast->next;
      if (fast)
        fast = fast->next;
      slow = slow->next;
      if (fast != nullptr && fast == slow) {
        fast = head;
        while (fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }
        return fast;
      }
    }
    return nullptr;
  }
};
