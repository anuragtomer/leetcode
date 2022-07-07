#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (!left)
      return !right;
    if (!right)
      return !left;
    return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
  }

 public:
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    return isSymmetric(root->left, root->right);
  }
};
int main() {
  Solution sol;

  return 0;
}

