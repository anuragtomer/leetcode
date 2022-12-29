#include <bitset>
#include <cassert>
#include "lib.hpp"
using namespace std;
using namespace trees;

class Solution {
  int paths(TreeNode *root, bitset<10> &seen) {
    if (!root)
      return 0;
    seen.flip(root->val);
    int val = 0;
    if (root->left == nullptr && root->right == nullptr) {
      if (seen.count() == 0 || seen.count() == 1)
        val = 1;
      seen.flip(root->val);
      return val;
    }
    val = paths(root->left, seen) + paths(root->right, seen);
    seen.flip(root->val);
    return val;
  }

 public:
  int pseudoPalindromicPaths(TreeNode *root) {
    bitset<10> seen;
    return paths(root, seen);
  }
};
int main() {
  Solution sol;
  auto root = trees::create_tree("2,3,1,3,1,null,1");
  assert(2 == sol.pseudoPalindromicPaths(root));
  delete_tree(root);
  root = trees::create_tree("2,1,1,1,3,null,null,null,null,null,1");
  assert(1 == sol.pseudoPalindromicPaths(root));
  delete_tree(root);
  root = trees::create_tree("9");
  assert(1 == sol.pseudoPalindromicPaths(root));
  delete_tree(root);
  return 0;
}
