#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution {
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr)
            return head;
        ListNode *previousHead = head;
        while (n--) {
            if (previousHead)
                previousHead = previousHead->next;
            else
                return head;
        }
        ListNode *toBeDeleted = head;
        if (previousHead == nullptr) {
            head = head->next;
            delete toBeDeleted;
            return head;
        }
        while (previousHead->next != nullptr) {
            previousHead = previousHead->next;
            toBeDeleted = toBeDeleted->next;
        }

        ListNode *temp = toBeDeleted->next;
        toBeDeleted->next = temp->next;
        delete temp;

        return head;
    }
};

int main() {
    Solution sol;
    ListNode *head = nullptr;
    vector<int> temp = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode *t = nullptr;
    while (!temp.empty()) {
        if (head == nullptr) {
            head = new ListNode(temp.back());
            temp.pop_back();
            t = head;
        } else {
            ListNode *t2 = new ListNode(temp.back());
            temp.pop_back();
            t->next = t2;
            t = t2;
        }
    }
    head = sol.removeNthFromEnd(head, n);
    cout << "List after operation: ";
    t = head;
    while (head) {
        cout << head->val;
        if (head->next)
            cout << "->";
        t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
