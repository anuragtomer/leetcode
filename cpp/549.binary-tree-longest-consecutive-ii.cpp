#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        val = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
    pair<int, int> helper(TreeNode *root, int &longestLength) {
        if (!root)
            return {0, 0};
        auto leftInfo = helper(root->left, longestLength);
        auto rightInfo = helper(root->right, longestLength);
        int leftIncr = leftInfo.first;
        int leftDecr = leftInfo.second;
        int rightIncr = rightInfo.first;
        int rightDecr = rightInfo.second;
        int currIncr = 0;
        int currDecr = 0;
        if (root->left != nullptr) {
            if (root->val == root->left->val - 1)
                currIncr = max(currIncr, leftIncr + 1);
            if (root->val == root->left->val + 1)
                currDecr = max(currDecr, leftDecr + 1);
        }
        if (root->right != nullptr) {
            if (root->val == root->right->val - 1)
                currIncr = max(currIncr, rightIncr + 1);
            if (root->val == root->right->val + 1)
                currDecr = max(currDecr, rightDecr + 1);
        }
        longestLength = max(longestLength, currDecr + currIncr + 1);
        return {currIncr, currDecr};
    }

   public:
    int longestConsecutive2(TreeNode *root) {
        int longestLength = 0;
        helper(root, longestLength);
        return longestLength;
    }
};

int main() {
    Solution sol;

    return 0;
}

