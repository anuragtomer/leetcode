#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    vector<int> nextLargerNodes(ListNode *head) {
        stack<int> st;
        vector<int> res;
        ListNode *temp = head;
        while (temp) {
            while (!st.empty() && res[st.top()] < temp->val) {
                res[st.top()] = temp->val;
                st.pop();
            }
            st.push(res.size());
            res.push_back(temp->val);
            temp = temp->next;
        }
        while (!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}

