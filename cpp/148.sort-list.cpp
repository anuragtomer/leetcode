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
  void divide(ListNode *head, ListNode *&list1, ListNode *&list2) {
    if (head == nullptr)
      return;
    ListNode *slow = head, *fast = head;
    if (fast)
      fast = fast->next;
    while (fast) {
      fast = fast->next;
      if (fast) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    list1 = head;
    list2 = slow->next;
    slow->next = nullptr;
  }
  void append(ListNode *&head, ListNode *&temp, ListNode *&list) {
    if (!head) {
      head = list;
      temp = list;
    } else {
      temp->next = list;
      temp = temp->next;
    }
    list = list->next;
  }
  ListNode *merge(ListNode *list1, ListNode *list2) {
    ListNode *head = nullptr, *temp = nullptr;
    while (list1 || list2) {
      if (list1 && list2) {
        if (list1->val < list2->val) {
          append(head, temp, list1);
        } else {
          append(head, temp, list2);
        }
      } else if (list1) {
        append(head, temp, list1);
      } else if (list2) {
        append(head, temp, list2);
      }
    }
    return head;
  }

 public:
  ListNode *sortList(ListNode *head) {
    if (!head || head->next == nullptr)
      return head;
    ListNode *list1 = nullptr, *list2 = nullptr;
    divide(head, list1, list2);
    list1 = sortList(list1);
    list2 = sortList(list2);
    return merge(list1, list2);
  }
};
int main() {
  Solution sol;

  return 0;
}
