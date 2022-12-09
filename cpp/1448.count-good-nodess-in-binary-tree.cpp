#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
  TreeNode(int _val, TreeNode *_left, TreeNode *_right)
    : val(_val), left(_left), right(_right) {}
};
class Solution {
  int goodNodes(TreeNode *node, int maxValue) {
    if (!node)
      return 0;
    if (node->val >= maxValue)
      return 1 + goodNodes(node->left, node->val) +
             goodNodes(node->right, node->val);
    else
      return goodNodes(node->left, maxValue) + goodNodes(node->right, maxValue);
  }

 public:
  int goodNodes(TreeNode *root) { return goodNodes(root, INT_MIN); }
};
void deleteTree(TreeNode *root) {
  if (root) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
  }
}
int main() {
  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(5);
  assert(4 == sol.goodNodes(root));
  deleteTree(root);
  root = new TreeNode(3);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(2);
  assert(3 == sol.goodNodes(root));
  deleteTree(root);
  return 0;
}

