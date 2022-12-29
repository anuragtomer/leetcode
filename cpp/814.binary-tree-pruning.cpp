#include <cassert>
#include "lib.hpp"
using namespace std;
using namespace trees;

class Solution {
  bool pruneRoot(TreeNode *&root) {
    if (!root)
      return true;

    if (root->left && pruneRoot(root->left))
      root->left = nullptr;
    if (root->right && pruneRoot(root->right))
      root->right = nullptr;
    if (root->left == nullptr && root->right == nullptr && root->val == 0) {
      delete root;
      root = nullptr;
      return true;
    } else
      return false;
  }

 public:
  TreeNode *pruneTree(TreeNode *root) {
    if (root && pruneRoot(root)) {
      delete root;
      root = nullptr;
      return nullptr;
    } else
      return root;
  }
};

int main() {
  Solution sol;
  TreeNode *root, *expected;
  root = create_tree("1,null,0,0,1", ',');
  expected = create_tree("1,null,0,null,1", ',');
  root = sol.pruneTree(root);
  assert(match_trees(expected, root));
  delete_tree(root);
  delete_tree(expected);
  return 0;
}
