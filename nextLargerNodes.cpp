#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution{
    public:
#if 0
Recursive Approach:
    void reverse(vector<int> &res) {
        int sz = res.size();
        int i, j;
        if (sz %2 == 0) {
            i = sz/2 - 1;
            j = i + 1;
        } else {
            i = sz/2 - 1;
            j = i + 2;
        }
        while (i >= 0) {
            int temp = res[i];
            res[i] = res[j];
            res[j] = temp;
            i--;
            j++;
        }
    }

    void nextLargerRecursive(ListNode *head, stack<int> &st, vector<int> &res) {
        if (head)
            nextLargerRecursive(head->next, st, res);
        if (!head)
            return;
        if (st.empty()) {
            res.push_back(0);
        } else {
            while(!st.empty() && st.top() <= head->val) {
                st.pop();
            }
            if (!st.empty())
                res.push_back(st.top());
            else
                res.push_back(0);
        }
        st.push(head->val);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> res;
        res.clear();
        nextLargerRecursive(head, st, res);
        reverse(res);
        return res;
    }
#endif
//Iterative Approach
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        res.clear();
        ListNode * temp  = head;
        while(temp) {
            while (!st.empty() && res[st.top()] <= temp->val) {
                res[st.top()] = temp->val;
                st.pop();
            }
            st.push(res.size());
            res.push_back(temp->val);
            temp = temp->next;
        }
        while(!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};
int main() {
    Solution sol;
    ListNode * head = new ListNode (1);
    ListNode * temp = head;
    temp-> next = new ListNode(7);
    temp = temp->next;
    temp->next = new ListNode(5);
    temp = temp->next;
    temp->next = new ListNode(1);
    temp = temp->next;
    temp->next = new ListNode(9);
    temp = temp->next;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(5);
    temp = temp->next;
    temp->next = new ListNode(1);
    vector<int> res = sol.nextLargerNodes(head);
    for (auto &i: res)
        cout << i << " ";
    return 0;
}


