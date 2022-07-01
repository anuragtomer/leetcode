#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution {
    int maxPathSum(TreeNode *root, int &max_sum) {
        if (!root)
            return 0;
        int left = maxPathSum(root->left, max_sum);
        int right = maxPathSum(root->right, max_sum);
        max_sum = max(max_sum, root->val + left + right);
        return max(0, root->val + max(left, right));
    }

   public:
    int maxPathSum(TreeNode *root) {
        int max_sum = INT_MIN;
        maxPathSum(root, max_sum);
        return max_sum;
    }
};

int main() {
    Solution sol;
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    TreeNode *root = new TreeNode(1, left, right);
    assert(6 == sol.maxPathSum(root));
    delete left;
    delete right;
    delete root;
    left = new TreeNode(15);
    right = new TreeNode(7);
    root = new TreeNode(20, left, right);
    left = new TreeNode(9);
    right = root;
    root = new TreeNode(-10, left, right);
    assert(42 == sol.maxPathSum(root));
    delete left;
    right = root->right;
    delete root;
    root = right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
