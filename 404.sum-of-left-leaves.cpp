#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of TreeNode:*/
class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

class Solution {
  void leftSum(TreeNode *root, int &sum, bool isLeft) {
    if (!root)
      return;
    if (root->left == nullptr && root->right == nullptr && isLeft) {
      sum += root->val;
      return;
    }
    leftSum(root->left, sum, true);
    leftSum(root->right, sum, false);
  }

 public:
  /**
     * @param root: t
     * @return: the sum of all left leaves
     */
  int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    bool isLeft = true;
    leftSum(root, sum, isLeft);
    return sum;
  }
};
int main() {
  Solution sol;

  return 0;
}

