#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};
class Solution {
    int helper(TreeNode *root, TreeNode *parent, int len) {
        if (!root)
            return len;
        len = (parent && (root->val == parent->val + 1)) ? len + 1 : 1;
        return max({len, helper(root->left, root, len), helper(root->right, root, len)});
    }

   public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode *root) { return helper(root, nullptr, 0); }
};

int main() {
    Solution sol;

    return 0;
}

