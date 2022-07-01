#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    void flatten(TreeNode *root) {
        if (!root)
            return;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *temp = nullptr, *last = nullptr;
        while (st.empty() == false || temp != nullptr) {
            if (temp == nullptr) {
                temp = st.top();
                st.pop();
                if (last)
                    last->right = temp;
            }
            if (temp->right)
                st.push(temp->right);
            temp->right = temp->left;
            temp->left = nullptr;
            last = temp;
            temp = temp->right;
        }
    }
};

int main() {
    Solution sol;

    return 0;
}

