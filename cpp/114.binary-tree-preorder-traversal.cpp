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
  void pre(TreeNode *root, vector<int> &result) {
    if (!root)
      return;
    result.push_back(root->val);
    pre(root->left, result);
    pre(root->right, result);
  }

 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    pre(root, result);
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

