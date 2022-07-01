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
  /* ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *temp = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                if (head == nullptr) {
                    head = l1;
                    temp = head;
                } else {
                    temp->next = l1;
                    temp = temp->next;
                }
                l1 = l1->next;
            } else {
                if (head == nullptr) {
                    head = l2;
                    temp = head;
                } else {
                    temp->next = l2;
                    temp = temp->next;
                }
                l2 = l2->next;
            }
        }
        while (l1 != nullptr) {
            if (head == nullptr) {
                return l1;
            } else {
                temp->next = l1;
                return head;
            }
        }
        while (l2 != nullptr) {
            if (head == nullptr) {
                return l2;
            } else {
                temp->next = l2;
                return head;
            }
        }
        return head;
    }*/

  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
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

 private:
  void append(ListNode *&head, ListNode *&temp, ListNode *&node) {
    if (!head) {
      head = node;
      temp = head;
    } else {
      temp->next = node;
      temp = temp->next;
    }
    node = node->next;
  }
};

int main() {
  Solution sol;

  return 0;
}

