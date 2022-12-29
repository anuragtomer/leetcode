#include "lib.hpp"

using namespace std;
using namespace trees;
class Solution {
 public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    if (original == target)
      return cloned;
    if (!original)
      return nullptr;
    TreeNode *found = nullptr;
    if (original->left)
      found = getTargetCopy(original->left, cloned->left, target);
    if (!found)
      found = getTargetCopy(original->right, cloned->right, target);
    return found;
  }
};

int main() {
  Solution sol;

  // Test case 1:
  string input = "7,4,3,null,null,6,19";
  TreeNode *original = create_tree(input, ',');
  TreeNode *cloned = create_tree(input, ',');
  TreeNode *target = original->right;
  assert(cloned->right == sol.getTargetCopy(original, cloned, target));
  delete_tree(original);
  delete_tree(cloned);

  // Test case 2:
  input = "7";
  original = create_tree(input, ',');
  cloned = create_tree(input, ',');
  target = original;
  assert(cloned == sol.getTargetCopy(original, cloned, target));
  delete_tree(original);
  delete_tree(cloned);

  // Test case 3:
  input = "8,null,6,null,5,null,4,null,3,null,2,null,1";
  original = create_tree(input, ',');
  cloned = create_tree(input, ',');
  target = original->right->right->right;
  assert(cloned->right->right->right ==
         sol.getTargetCopy(original, cloned, target));
  delete_tree(original);
  delete_tree(cloned);

  // Test case 4:
  input = "1,2,3,4,5,6,7,8,9,10";
  original = create_tree(input, ',');
  cloned = create_tree(input, ',');
  target = original->left->right;
  assert(cloned->left->right == sol.getTargetCopy(original, cloned, target));
  delete_tree(original);
  delete_tree(cloned);
  return 0;
}
