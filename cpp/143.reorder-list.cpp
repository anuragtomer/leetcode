#include <cassert>
#include <iostream>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace lists;
class Solution {
  pair<ListNode *, ListNode *> split(ListNode *head) {
    ListNode *oddH = head;
    ListNode *oddT = oddH, *evenT = head ? head->next : nullptr;
    while (evenT) {
      evenT = evenT->next;
      if (evenT) {
        evenT = evenT->next;
        oddT = oddT->next;
      }
    }
    auto evenH = oddT->next;
    oddT->next = nullptr;
    return {oddH, evenH};
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
  void merge(ListNode *list1, ListNode *list2, ListNode *&head) {
    head = list1;
    while (list1 && list2) {
      auto next1 = list1->next, next2 = list2->next;
      list1->next = list2;
      list2->next = next1;
      list1 = next1;
      list2 = next2;
    }
  }

 public:
  void reorderList(ListNode *&head) {
    auto [oddH, evenH] = split(head);
    evenH = reverse(evenH);
    merge(oddH, evenH, head);
  }
};
int main() {
  Solution sol;
  ListNode *head = create_list("1,2,3,4");
  ListNode *expected = create_list("1,4,2,3");
  sol.reorderList(head);
  assert(match_lists(head, expected));
  delete_list(head);
  delete_list(expected);
  head = create_list("1,2,3,4,5");
  expected = create_list("1,5,2,4,3");
  sol.reorderList(head);
  assert(match_lists(head, expected));
  delete_list(head);
  delete_list(expected);
  return 0;
}
