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
  void getinorder(TreeNode *root, vector<int> &result) {
    if (!root)
      return;
    getinorder(root->left, result);
    result.push_back(root->val);
    getinorder(root->right, result);
  }

 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    getinorder(root, result);
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

