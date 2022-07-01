#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int d) : data(d), next(nullptr){};
    ListNode() : next(nullptr){};

    ListNode *createList(vector<int> &num) {
        ListNode *head = nullptr;
        if (num.size() >= 1)
            head = new ListNode(num[0]);
        else
            return nullptr;
        ListNode *temp = head;
        for (auto i = 1; i < num.size(); ++i) {
            temp->next = new ListNode(num[i]);
            temp = temp->next;
        }
        return head;
    }
};

class Solution {
   public:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    Solution sol;
    ListNode ln;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    ListNode *head = ln.createList(arr);
    ListNode *middle = sol.middleNode(head);
    if (middle != nullptr)
        cout << middle->data;
    else
        cout << "Incorrect node";
    return 0;
}