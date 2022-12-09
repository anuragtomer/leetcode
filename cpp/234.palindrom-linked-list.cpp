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
  ListNode *getMidPoint(ListNode *head) {
    ListNode *slow = head, *fast = head;
    if (fast)
      fast = fast->next;
    while (fast) {
      fast = fast->next;
      if (fast) {
        fast = fast->next;
        slow = slow->next;
      }
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;
    return mid;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *current = head, *prev = nullptr, *next = nullptr;
    while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }

  bool areTheySame(ListNode *list1, ListNode *list2) {
    while (list1 && list2) {
      if (list1->val != list2->val)
        return false;
      list1 = list1->next;
      list2 = list2->next;
    }
    return true;
  }

 public:
  bool isPalindrom(ListNode *head) {
    auto midPoint = getMidPoint(head);
    auto reverseHead = reverse(midPoint);
    return areTheySame(head, reverseHead);
  }
};

void append(ListNode *&last, int val) {
  if (last == nullptr)
    last = new ListNode(val);
  else
    last->next = new ListNode(val);
}

void freeMem(ListNode *&head) {
  while (head) {
    ListNode *toBeDeleted = head;
    head = head->next;
    delete toBeDeleted;
  }
}

int main() {
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);
  assert(sol.isPalindrom(head));
  freeMem(head);
  head = nullptr;
  head = new ListNode(1);
  head->next = new ListNode(2);
  assert(not sol.isPalindrom(head));
  freeMem(head);
  return 0;
}
