#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of TreeNode:*/
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
   public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    pair<int, double> helper(TreeNode *root, double target) {
        if (!root)
            return {0, INT_MAX};
        pair<int, double> child;
        if (root->val == target)
            return {root->val, 0};
        else if (target > root->val)
            child = helper(root->right, target);
        else
            child = helper(root->left, target);
        pair<int, double> current = {root->val, abs(root->val - target)};
        return (child.second < current.second) ? child : current;
    }
    int closestValue(TreeNode *root, double target) {
        if (!root)
            return INT_MAX;
        return helper(root, target).first;
    }
};
int main() {
    Solution sol;

    return 0;
}

