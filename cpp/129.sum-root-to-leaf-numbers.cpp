#include <iostream>
#include <queue>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
    int sumNumbers(TreeNode *root, int currentSum) {
        if (!root->left && !root->right)
            return currentSum * 10 + root->val;
        else {
            int newSum = 0;
            currentSum = currentSum * 10 + root->val;
            if (root->left)
                newSum += sumNumbers(root->left, currentSum);
            if (root->right)
                newSum += sumNumbers(root->right, currentSum);
            return newSum;
        }
    }

   public:
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        return sumNumbers(root, 0);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    TreeNode *root = createTree(nums);
    assert(25 == sol.sumNumbers(root));
    deleteTree(root);
    nums = {4, 9, 0, 5, 1};
    root = createTree(nums);
    assert(1026 == sol.sumNumbers(root));
    deleteTree(root);
    return 0;
}
