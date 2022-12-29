#include <iostream>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;

class Solution {
 public:
  // Recursive
  TreeNode *searchBST(TreeNode *root, int val) {
    if (!root)
      return nullptr;
    if (root->val == val)
      return root;
    return (root->val < val) ? searchBST(root->right, val)
                             : searchBST(root->left, val);
  }
  /* Iterative */
  /* 
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root) {
            if (root->val == val)
                return root;
            root = (root->val < val) ? root->right : root->left;
        }
        return nullptr;
    } 
    */
};

int main() {
  Solution sol;
  TreeNode *root = create_tree("4,2,7,1,3", ',');
  TreeNode *expected = create_tree("2,1,3", ',');
  TreeNode *output = sol.searchBST(root, 2);
  assert(match_trees(output, expected));
  delete_tree(root);
  delete_tree(expected);
  return 0;
}
