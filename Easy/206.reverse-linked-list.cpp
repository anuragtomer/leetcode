/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

#include <iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


// @lc code=start
class Solution {
public:
    /* Recursive */
    ListNode * reverseList(ListNode * head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode * temp = reverseList(head->next); // No need to return pointer to last element. Head already points to last element of the 'now' reversed list.
        head->next->next = head; // We know that head->next points to last element of the now reversed list. Make that element point to head so as to add head to the end of the list.
        head->next = nullptr; // Make head the last element of the list.
        return temp;
    }
    /* 
        Iterative Approach
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode * temp = head->next;
        head->next = nullptr;
        ListNode *temp2 = temp->next;
        while(temp != nullptr) {
            temp->next = head;
            head = temp;
            temp = temp2;
            if (temp2 != nullptr)
                temp2 = temp2->next;
        }
        return head;
    } 
    */
};
// @lc code=end

void printList(ListNode * head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}
int main() {
    Solution sol;
    ListNode * head =  new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    printList(head);
    head = sol.reverseList(head);
    printList(head);
    return 0;
}