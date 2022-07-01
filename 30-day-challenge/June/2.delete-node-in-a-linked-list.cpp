#include <iostream>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
   public:
    void deleteNode(ListNode *node) {
        auto nxt = node->next;
        node->val = nxt->val;
        node->next = nxt->next;
        delete nxt;
    }
};

int main() {
    Solution sol;
    string s = "4,5,1,9";
    ListNode *head = stringToList(s);
    sol.deleteNode(head->next);
    string output = stringFromList(head);
    string expected = "4,1,9";
    assert(output.compare(expected) == 0);
    return 0;
}
