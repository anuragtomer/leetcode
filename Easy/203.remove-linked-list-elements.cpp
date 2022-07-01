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
 public:
  ListNode *removeElements(ListNode *head, int val) {
    while (head && head->val == val) {
      ListNode *temp = head;
      head = head->next;
      delete temp;
    }
    if (!head)
      return head;
    ListNode *temp = head, *next = head->next;
    while (next) {
      if (next->val == val) {
        ListNode *toBeDeleted = next;
        next = next->next;
        delete toBeDeleted;
        temp->next = next;
      } else {
        temp = next;
        next = next->next;
      }
    }
    return head;
  }
};

int main() {
  Solution sol;

  return 0;
}

