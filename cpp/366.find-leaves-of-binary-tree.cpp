#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of TreeNode:
 */
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
    int helper(TreeNode *root, vector<vector<int>> &result) {
        if (!root) {
            return -1;
        }
        int leftHeight = helper(root->left, result);
        int rightHeight = helper(root->right, result);
        int height = max(leftHeight, rightHeight) + 1;
        if (result.size() <= height) {
            result.resize(height + 1);
        }
        result[height].push_back(root->val);
        return height;
    }

   public:
    vector<vector<int>> findLeaves(TreeNode *root) {
        vector<vector<int>> result;
        helper(root, result);
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

