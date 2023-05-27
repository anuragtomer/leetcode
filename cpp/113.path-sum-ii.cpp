#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *_left, TreeNode *_right)
    : val(x), left(_left), right(_right) {}
};
class Solution {
  void helper(TreeNode *root, int targetSum, vector<int> &current,
              vector<vector<int>> &result) {
    if (!root)
      return;
    if (root && !root->left && !root->right) {
      if (root->val == targetSum) {
        current.push_back(root->val);
        result.push_back(current);
        current.pop_back();
      }
      return;
    }
    current.push_back(root->val);
    if (root->left)
      helper(root->left, targetSum - root->val, current, result);
    if (root->right)
      helper(root->right, targetSum - root->val, current, result);
    current.pop_back();
  }

 public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> result;
    vector<int> current;
    helper(root, targetSum, current, result);
    return result;
  }
};

void deleteTree(TreeNode *root) {
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
  return;
}

int main() {
  Solution sol;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(1);
  vector<vector<int>> output = sol.pathSum(root, 22);
  vector<vector<int>> expected = {{5, 4, 11, 2}, {5, 8, 4, 5}};
  assert(output.size() == expected.size());
  for (int i = 0; i < expected.size(); ++i) {
    assert(output[i].size() == expected[i].size());
    for (int j = 0; j < expected[i].size(); ++j) {
      assert(output[i][j] == expected[i][j]);
    }
  }
  deleteTree(root);
  cout << "Testcase passed";
  return 0;
}
