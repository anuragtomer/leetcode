
#include <iostream>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
   public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr)
            return head;
        ListNode *evenHead = head->next;
        if (evenHead == nullptr)
            return head;
        ListNode *oddTemp = head;
        ListNode *evenTemp = evenHead;
        while (evenTemp) {
            oddTemp->next = evenTemp->next;
            if (evenTemp->next)
                evenTemp->next = evenTemp->next->next;
            if (oddTemp->next)
                oddTemp = oddTemp->next;
            evenTemp = evenTemp->next;
        }
        oddTemp->next = evenHead;
        return head;
    }
};

int main() {
    Solution sol;
    string list = "1,2,3,4,5";
    ListNode *head = createList(list);
    string output = "1,3,5,2,4";
    assert(output == stringFromList(sol.oddEvenList(head)));
    deleteList(head);
    list = "2,1,3,5,6,4,7";
    output = "2,3,6,7,1,5,4";
    head = createList(list);
    assert(output == stringFromList(sol.oddEvenList(head)));
    deleteList(head);
    return 0;
}
