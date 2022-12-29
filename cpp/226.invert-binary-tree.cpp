#include <iostream>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
  }
};

int main() {
  Solution sol;
  auto root = create_tree("4,2,7,1,3,6,9", ',');
  root = sol.invertTree(root);
  auto expected = create_tree("4,7,2,9,6,3,1", ',');
  assert(match_trees(root, expected));
  delete_tree(root);
  delete_tree(expected);
  return 0;
}
