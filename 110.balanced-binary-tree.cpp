/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  struct balancedData {
    bool balanced;
    int height;
    balancedData(bool _balanced, int _height)
      : balanced(_balanced), height(_height) {}
  };
  balancedData helper(TreeNode *root) {
    if (!root) {
      return {true, 0};
    }
    balancedData left = helper(root->left), right = helper(root->right);
    if (left.balanced == false || right.balanced == false)
      return {false, 0};
    if (abs(left.height - right.height) > 1)
      return {false, 0};
    return {true, 1 + max(left.height, right.height)};
  }

 public:
  bool isBalanced(TreeNode *root) { return helper(root).balanced; }
};
