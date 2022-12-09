/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  // One round O(m+n) algo:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *listA = headA, *listB = headB;
    bool movedA = false, movedB = false;
    while (listA && listB) {
      if (listA == listB)
        return listA;
      listA = listA->next;
      if (listA == nullptr && not movedA) {
        listA = headB;
        movedA = true;
      }
      listB = listB->next;
      if (listB == nullptr && not movedB) {
        listB = headA;
        movedB = true;
      }
    }
    return nullptr;
  }
};
