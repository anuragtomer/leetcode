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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
      if (curr->next && curr->val == curr->next->val) {
        ListNode *toBeDeleted = curr->next;
        curr->next = curr->next->next;
        delete toBeDeleted;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};

int main() {
  Solution sol;

  return 0;
}

