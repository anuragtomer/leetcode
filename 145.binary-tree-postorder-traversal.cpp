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
  void getPostorder(TreeNode *root, vector<int> &result) {
    if (!root)
      return;
    getPostorder(root->left, result);
    getPostorder(root->right, result);
    result.push_back(root->val);
  }

 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    getPostorder(root, result);
    return result;
  }
};

int main() {
  Solution sol;

  return 0;
}

