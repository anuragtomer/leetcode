#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of singly-linked-list:*/
class ListNode {
 public:
  int val;
  ListNode *next;
  ListNode(int val) {
    this->val = val;
    this->next = NULL;
  }
};

class Solution {
 public:
  /**
    * @param head: the head of linked list.
    * @return: a middle node of the linked list
    */
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    if (fast)
      fast = fast->next;
    while (fast) {
      fast = fast->next;
      if (fast) {
        fast = fast->next;
        slow = slow->next;
      } else
        return slow;
    }
    return slow;
  }
};
int main() {
  Solution sol;

  return 0;
}

