/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */
#include<iostream>
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
    void deleteNode(ListNode* node) {
        ListNode * temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
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
    ListNode * node = head->next->next;
    printList(head);
    sol.deleteNode(node);
    printList(head);
    return 0;
}