#include <algorithm>
#include <iostream>
#include <vector>

#include "lib.hpp"
using trees::TreeNode;
using namespace std;

class Solution {
 public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (postorder.empty() || inorder.empty()) {
      return nullptr;
    }
    int val = postorder.back();
    int found_at = -1;
    for (int i = 0; i < inorder.size(); ++i) {
      if (inorder[i] == val) {
        found_at = i;
        break;
      }
    }
    if (found_at == -1) {
      return nullptr;
    }
    postorder.pop_back();
    TreeNode *root = new TreeNode(val);
    vector<int> left_inorder =
      vector<int>(inorder.begin(), inorder.begin() + found_at);
    vector<int> right_inorder =
      vector<int>(inorder.begin() + found_at + 1, inorder.end());
    root->right = buildTree(right_inorder, postorder);
    root->left = buildTree(left_inorder, postorder);
    return root;
  }
};

int main() {
  Solution sol;
  vector<int> inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
  TreeNode *root = sol.buildTree(inorder, postorder);
  assert(root != nullptr);
  assert(root->val == 3);
  assert(root->left != nullptr);
  assert(root->left->val == 9);
  assert(root->left->left == nullptr);
  assert(root->left->right == nullptr);
  assert(root->right != nullptr);
  assert(root->right->val == 20);
  assert(root->right->left != nullptr);
  assert(root->right->left->val == 15);
  assert(root->right->left->left == nullptr);
  assert(root->right->left->right == nullptr);
  assert(root->right->right != nullptr);
  assert(root->right->right->val == 7);
  assert(root->right->right->left == nullptr);
  assert(root->right->right->right == nullptr);
  return 0;
}
