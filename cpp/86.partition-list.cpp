struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  void append(ListNode *&head, ListNode *&temp, ListNode *&list) {
    if (!head) {
      head = list;
      temp = list;
    } else {
      temp->next = list;
      temp = temp->next;
    }
    list = list->next;
  }

 public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *less = nullptr, *less_temp = nullptr, *more = nullptr,
             *more_temp = nullptr;
    while (head) {
      if (head->val < x) {
        append(less, less_temp, head);
      } else {
        append(more, more_temp, head);
      }
    }
    if (more)
      more_temp->next = nullptr;
    if (less) {
      less_temp->next = more;
      return less;
    }
    return more;
  }
};
