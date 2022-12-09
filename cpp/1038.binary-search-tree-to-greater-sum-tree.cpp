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
  void helper(TreeNode *root, int &sum) {
    if (!root)
      return;
    if (root->left == nullptr && root->right == nullptr) {
      root->val += sum;
      sum = root->val;
      return;
    }
    helper(root->right, sum);
    root->val += sum;
    sum = root->val;
    helper(root->left, sum);
    return;
  }

 public:
  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    helper(root, sum);
    return root;
  }
};
int main() {
  Solution sol;

  return 0;
}

