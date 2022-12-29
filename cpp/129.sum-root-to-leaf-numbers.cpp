#include <iostream>
#include <queue>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;

class Solution {
  int sumNumbers(TreeNode *root, int currentSum) {
    if (!root->left && !root->right)
      return currentSum * 10 + root->val;
    else {
      int newSum = 0;
      currentSum = currentSum * 10 + root->val;
      if (root->left)
        newSum += sumNumbers(root->left, currentSum);
      if (root->right)
        newSum += sumNumbers(root->right, currentSum);
      return newSum;
    }
  }

 public:
  int sumNumbers(TreeNode *root) {
    if (!root)
      return 0;
    return sumNumbers(root, 0);
  }
};

int main() {
  Solution sol;
  string nums = "1,2,3";
  TreeNode *root = create_tree(nums, ',');
  assert(25 == sol.sumNumbers(root));
  delete_tree(root);
  nums = "4,9,0,5,1";
  root = create_tree(nums, ',');
  assert(1026 == sol.sumNumbers(root));
  delete_tree(root);
  return 0;
}
