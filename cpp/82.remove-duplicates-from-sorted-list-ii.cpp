struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  bool deleteSame(ListNode *&list) {
    bool deleted = false;
    while (list && list->next && list->val == list->next->val) {
      auto to_be_deleted = list->next;
      list->next = list->next->next;
      delete to_be_deleted;
      deleted = true;
    }
    return deleted;
  }

 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next)
      return head;
    while (deleteSame(head)) {
      auto to_be_deleted = head;
      head = head->next;
      delete to_be_deleted;
    }
    ListNode *temp = head;
    while (temp) {
      auto next = temp->next;
      if (deleteSame(next) && next) {
        temp->next = next->next;
        delete next;
      } else {
        temp = temp->next;
      }
    }
    return head;
  }
};
