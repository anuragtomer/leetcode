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
  ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *evenHead = head->next, *even = head->next, *oddHead = head, *odd = head;
    while (even && odd) {
      odd->next = even->next;
      if (odd->next)
        odd = odd->next;
      even->next = odd ? odd->next : nullptr;
      even = even->next;
    }
    odd->next = evenHead;
    return head;
  }
};
int main() {
  Solution sol;

  return 0;
}

