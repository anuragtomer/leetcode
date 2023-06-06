#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
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

int main() {
  Solution sol;
  auto lDeleteListNode = [](ListNode *head) {
    return;
    // Find a clean way to free up memory.
    while (head) {
      auto temp = head;
      head = head->next;
      delete temp;
      temp = nullptr;
    }
  };
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  assert(head->next == sol.detectCycle(head));
  lDeleteListNode(head);
  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = head;
  assert(head == sol.detectCycle(head));
  lDeleteListNode(head);
  head = new ListNode(1);
  assert(nullptr == sol.detectCycle(head));
  lDeleteListNode(head);
  return 0;
}
