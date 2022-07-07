#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
class Solution {
   public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    Solution sol;

    return 0;
}

