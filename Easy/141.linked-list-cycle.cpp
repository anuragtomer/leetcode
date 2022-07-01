#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head)
      return false;
    ListNode *slow = head, *fast = head->next;
    while (fast && slow != fast) {
      slow = slow->next;
      fast = fast->next;
      if (fast)
        fast = fast->next;
    }
    return slow == fast;
  }
};

int main() {
  Solution sol;

  return 0;
}

