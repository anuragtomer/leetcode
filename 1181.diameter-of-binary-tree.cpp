#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  int diameterOfBinaryTree(TreeNode *root, int &maxDiameter) {
    if (!root)
      return 0;
    int leftDepth = diameterOfBinaryTree(root->left, maxDiameter);
    int rightDepth = diameterOfBinaryTree(root->right, maxDiameter);
    if (maxDiameter < leftDepth + rightDepth)
      maxDiameter = leftDepth + rightDepth;
    return max(leftDepth, rightDepth) + 1;
  }

 public:
  int diameterOfBinaryTree(TreeNode *root) {
    int maxDiameter = 0;
    diameterOfBinaryTree(root, maxDiameter);
    return maxDiameter;
  }
};
int main() {
  Solution sol;

  return 0;
}

