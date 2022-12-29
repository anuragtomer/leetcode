#include <iostream>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace lists;

class Solution {
 public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      if (fast->next)
        fast = fast->next->next;
    }
    return slow;
  }
};

int main() {
  Solution sol;
  ListNode *head = from_vec({1, 2, 3, 4, 5, 6});
  ListNode *middle = sol.middleNode(head);
  if (middle != nullptr)
    cout << middle->val;
  else
    cout << "Incorrect node";
  return 0;
}