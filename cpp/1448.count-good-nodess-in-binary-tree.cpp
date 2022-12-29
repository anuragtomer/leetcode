#include <algorithm>
#include <iostream>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;
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
int main() {
  Solution sol;
  auto root = create_tree("3,1,4,3,null,1,5");
  assert(4 == sol.goodNodes(root));
  delete_tree(root);
  root = new TreeNode(3);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(2);
  auto root = create_tree("3,3,null,4,2");
  assert(3 == sol.goodNodes(root));
  delete_tree(root);
  return 0;
}
