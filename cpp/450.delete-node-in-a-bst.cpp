struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : left(nullptr), right(nullptr) {}
  TreeNode(int _val) : val(_val) { TreeNode(); }
  TreeNode(int _val, TreeNode *_left, TreeNode *_right)
    : val(_val), left(_left), right(_right) {}
};
class Solution {
 public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return root;
    if (root->val == key) {
      if (root->right == nullptr) {
        TreeNode *left = root->left;
        delete root;
        return left;
      } else {
        TreeNode *succ = root->right;
        while (succ->left)
          succ = succ->left;
        swap(succ->val, root->val);
        root->right = deleteNode(root->right, key);
        return root;
      }
    } else if (root->val > key)
      root->left = deleteNode(root->left, key);
    else
      root->right = deleteNode(root->right, key);
    return root;
  }
};
