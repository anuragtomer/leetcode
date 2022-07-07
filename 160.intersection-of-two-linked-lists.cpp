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
 
// @lc code=start
class Solution {
public:
    // One round O(m+n) algo:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        if (pA == nullptr || pB == nullptr)
            return nullptr;
        bool reassignedA = false;
        bool reassignedB = false;
        while(pA != nullptr && pB != nullptr) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
            if (pA == nullptr) {
                if (reassignedA == false)
                    reassignedA = true;
                else
                    return nullptr;
                pA = headB;
            }
            if (pB == nullptr) {
                if (reassignedB == false)
                    reassignedB = true;
                else
                    return nullptr;
                pB = headA;
            }
        }
        return pA;
    }
/* 
    int findLength(ListNode * head) {
        int count = 0;
        while(head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }
    // O(4n)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = findLength(headA);
        int lenB = findLength(headB);
        while (lenA > lenB) {
            headA = headA->next;
            --lenA;
        }
        while (lenB > lenA) {
            headB = headB->next;
            --lenB;
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
 */
};
// @lc code=end
