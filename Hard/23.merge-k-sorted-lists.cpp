#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    /* Solution 1:
           ListNode *mergeKLists(vector<ListNode *> &lists) {
            ListNode *mergedHead = nullptr, *mergedTemp = nullptr, *minNode = nullptr;
            bool foundOne = true;
            int minVal = INT_MAX;
            while (foundOne == true) {
                foundOne = false;
                minNode = nullptr;
                minVal = INT_MAX;
                for (auto &head : lists) {
                    if (head != nullptr) {
                        foundOne = true;
                        if (minVal > head->val) {
                            minVal = head->val, minNode = head;
                        }
                    }
                }
                if (foundOne == false)
                    break;
                // By now, I should have min head out of all lists.
                if (mergedHead == nullptr) {
                    mergedHead = minNode;
                    minNode = minNode->next;
                    mergedTemp = mergedHead;
                } else {
                    mergedTemp->next = minNode;
                    minNode = minNode->next;
                    mergedTemp = mergedTemp->next;
                }
            }
            return mergedHead;
        }
        */
    /* Solution 2: */
    /*
 ListNode *merge2Lists(ListNode *one, ListNode *two) {
     if (one == nullptr)
         return two;
     if (two == nullptr)
         return one;
     ListNode *head = nullptr, *temp = nullptr;
     while (one != nullptr && two != nullptr) {
         if (one->val < two->val) {
             if (head == nullptr) {
                 head = one;
                 temp = head;
                 one = one->next;
             } else {
                 temp->next = one;
                 one = one->next;
                 temp = temp->next;
             }
         } else {
             if (head == nullptr) {
                 head = two;
                 temp = head;
                 two = two->next;
             } else {
                 temp->next = two;
                 temp = temp->next;
                 two = two->next;
             }
         }
     }
     if (one == nullptr) {
         temp->next = two;
     } else if (two == nullptr)
         temp->next = one;
     return head;
 }

 ListNode *mergeKLists(vector<ListNode *> lists) {
     int size = lists.size();
     if (size == 0)
         return nullptr;
     if (size == 1)
         return lists[0];
     if (size == 2)
         return merge2Lists(lists[0], lists[1]);
     return merge2Lists(mergeKLists(vector<ListNode *>(lists.begin(), lists.begin() + size / 2)),
                        mergeKLists(vector<ListNode *>(lists.begin() + size / 2, lists.end())));
 } */

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);
        ListNode *head = nullptr, *temp = nullptr;
        int i = 0;
        for (auto lst : lists) {
            i++;
            if (lst != nullptr)
                pq.push(lst);
        }
        while (!pq.empty()) {
            auto minNode = pq.top();
            pq.pop();
            if (head == nullptr) {
                head = minNode;
                temp = head;
            } else {
                temp->next = minNode;
                temp = temp->next;
            }
            minNode = minNode->next;
            if (minNode != nullptr)
                pq.push(minNode);
        }
        return head;
    }
};

int main() {
    Solution sol;
    vector<ListNode *> lists;
    //    [1,4,5],[1,3,4],[2,6]]
    ListNode *first = new ListNode(1);
    first->next = new ListNode(4);
    first->next->next = new ListNode(5);
    ListNode *second = new ListNode(1);
    second->next = new ListNode(3);
    second->next->next = new ListNode(4);
    ListNode *third = new ListNode(2);
    third->next = new ListNode(6);
    lists.push_back(first);
    lists.push_back(second);
    lists.push_back(third);
    ListNode *merged = sol.mergeKLists(lists);
    while (merged != nullptr) {
        cout << merged->val << " ";
        merged = merged->next;
    }

    return 0;
}

