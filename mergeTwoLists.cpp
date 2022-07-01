#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* l3 = NULL;
            ListNode* l3_head = NULL;
            while(l1 != NULL && l2 != NULL) {            
                if (l1->val < l2->val) {
                    if (l3_head != NULL) {
                        l3->next = l1;                    
                    } else {
                        l3_head = l1;
                        l3 = l3_head;
                    }
                    l1 = l1->next;
                } else {
                    if (l3_head != NULL) {
                        l3->next = l2;
                    } else {
                        l3_head = l2;
                        l3 = l3_head;
                    }
                    l2 = l2->next;
                }
            }
            if (l1 != NULL) {
                if (l3_head == NULL)
                    l3_head = l1;
                else 
                    l3->next = l1;
            } else if (l2 != NULL) {
                if (l3_head == NULL) 
                    l3_head = l2;
                else
                    l3->next = l2;
            }
            return l3_head;
        }
};

int main() {
    Solution sol;
   
    return 0;
}

