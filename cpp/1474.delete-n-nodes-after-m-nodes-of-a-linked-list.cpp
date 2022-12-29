#include <algorithm>
#include <iostream>
#include <vector>
#include "lib.hpp"

using namespace std;

class Solution {
 public:
  Lists::ListNode *deleteNodes(Lists::ListNode *head, int m, int n) {
    Lists::ListNode *prev = nullptr, *curr = head;
    while (curr) {
      for (int i = 0; i < m && curr != nullptr; ++i) {
        prev = curr;
        curr = curr->next;
      }
      for (int i = 0; i < n && curr != nullptr; ++i) {
        prev->next = curr->next;
        curr = curr->next;
      }
    }
    return head;
  }
};

int main() {
  Solution sol;

  assert(match_lists(
    sol.deleteNodes(
      Lists::from_vec({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}), 2, 3),
    Lists::from_vec({1, 2, 6, 7, 11, 12})));
  cout << "Pass 1" << endl;

  assert(match_lists(
    sol.deleteNodes(Lists::from_vec({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}), 1, 3),
    Lists::from_vec({1, 5, 9})));
  cout << "Pass 2" << endl;

  assert(match_lists(
    sol.deleteNodes(Lists::from_vec({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}), 3, 1),
    Lists::from_vec({1, 2, 3, 5, 6, 7, 9, 10, 11})));
  cout << "Pass 3" << endl;

  assert(match_lists(
    sol.deleteNodes(Lists::from_vec({9, 2, 7, 7, 9, 10, 8, 2}), 1, 2),
    Lists::from_vec({9, 7, 8})));
  cout << "Pass 4" << endl;

  return 0;
}
