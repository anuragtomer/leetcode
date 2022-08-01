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
int main() {
  Solution sol;

  return 0;
}
