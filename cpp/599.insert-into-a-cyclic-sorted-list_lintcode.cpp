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
    this->next = nullptr;
  }
};

class Solution {
 public:
  /**
    * @param node: a list node in the list
    * @param x: An integer
    * @return: the inserted new list node
    */
  ListNode *insert(ListNode *node, int x) {
    ListNode *newNode = new ListNode(x);
    if (!node) {
      newNode->next = newNode;
      return newNode;
    }
    ListNode *temp = node, *last = nullptr;
    while (temp != nullptr && temp->val < x) {
      last = temp;
      temp = temp->next;
      if (temp == node)
        break;
    }
    if (last == nullptr) {
      newNode->next = node;
      ListNode *temp = node;
      while (temp->next != node) {
        temp = temp->next;
      }
      temp->next = newNode;
      return newNode;
    } else {
      newNode->next = temp;
      last->next = newNode;
      return node;
    }
  }
};

int main() {
  Solution sol;
  return 0;
}

