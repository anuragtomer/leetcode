#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};
class Solution {
  bool helper(TreeNode *root, TreeNode *subRoot) {
    if (!root)
      return subRoot == nullptr;
    if (!subRoot)
      return false;
    return (root->val == subRoot->val) && helper(root->left, subRoot->left) &&
           helper(root->right, subRoot->right);
  }

 public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    return helper(root, subRoot) || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }
};

int main() {
  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  TreeNode *subtree = new TreeNode(4);
  subtree->left = new TreeNode(1);
  subtree->right = new TreeNode(2);
  assert(sol.isSubtree(root, subtree));
  function<void(TreeNode *)> lDeleteTree = [&](TreeNode *root) -> void {
    if (!root)
      return;
    lDeleteTree(root->left);
    lDeleteTree(root->right);
    delete root;
  };
  lDeleteTree(root);
  lDeleteTree(subtree);
  return 0;
}
