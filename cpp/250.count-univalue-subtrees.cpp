#include "lib.hpp"
using namespace std;
using namespace trees;

class Solution {
  bool helper(TreeNode *root, int val, int &count) {
    if (not root) {
      return true;
    }
    bool left = helper(root->left, root->val, count);
    bool right = helper(root->right, root->val, count);
    if (not left || not right) {
      return false;
    }
    ++count;
    return val == root->val;
  }

 public:
  int countUnivalSubtrees(TreeNode *root) {
    int count = 0;
    helper(root, INT_MIN, count);
    return count;
  }
};

int main() {
  Solution sol;
  auto root = trees::create_tree("5,1,5,5,5,null,5");
  assert(4 == sol.countUnivalSubtrees(root));
  trees::delete_tree(root);
  root = trees::create_tree("1,3,2,4,5,null,6");
  assert(3 == sol.countUnivalSubtrees(root));
  trees::delete_tree(root);
  return 0;
}
