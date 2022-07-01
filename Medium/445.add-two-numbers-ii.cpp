#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr, *current = head, *next = nullptr;
    while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }

 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    int carry = 0;
    ListNode *head = nullptr, *temp = nullptr;
    while (carry || l1 || l2) {
      carry = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      if (l1) {
        l1->val = carry % 10;
        if (!head) {
          head = l1;
          temp = head;
        } else {
          temp->next = l1;
          temp = temp->next;
        }
      } else if (l2) {
        l2->val = carry % 10;
        if (!head) {
          head = l2;
          temp = head;
        } else {
          temp->next = l2;
          temp = temp->next;
        }
      } else {
        if (!head) {
          head = new ListNode(carry % 10);
          temp = head;
        } else {
          temp->next = new ListNode(carry % 10);
          temp = temp->next;
        }
      }
      carry = carry / 10;
      l1 = (l1 ? l1->next : nullptr);
      l2 = (l2 ? l2->next : nullptr);
    }
    head = reverse(head);
    return head;
  }
};
int main() {
  Solution sol;

  return 0;
}

