#include <iostream>
#include <stack>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
   public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> st;
        while (root) {
            st.push(root);
            root = root->left;
        }

        TreeNode *curr;
        while (k && !st.empty()) {
            k--;
            if (k == 0)
                return st.empty() ? -1 : st.top()->val;
            curr = st.top();
            st.pop();
            if (curr->right) {
                TreeNode *temp = curr->right;
                while (temp) {
                    st.push(temp);
                    temp = temp->left;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string input = "5,3,6,2,4,null,null,1";
    TreeNode *root = createTree(input, ',');
    assert(1 == sol.kthSmallest(root, 1));
    assert(2 == sol.kthSmallest(root, 2));
    assert(3 == sol.kthSmallest(root, 3));
    assert(4 == sol.kthSmallest(root, 4));
    assert(5 == sol.kthSmallest(root, 5));
    assert(6 == sol.kthSmallest(root, 6));
    deleteTree(root);
    input = "3,1,4,null,2";
    root = createTree(input, ',');
    assert(1 == sol.kthSmallest(root, 1));
    assert(2 == sol.kthSmallest(root, 2));
    assert(3 == sol.kthSmallest(root, 3));
    assert(4 == sol.kthSmallest(root, 4));
    deleteTree(root);

    return 0;
}
