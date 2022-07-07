#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = nullptr;
  }
};

class Solution {
  void helper(TreeNode *root, string current, vector<string> &result) {
    if (!root)
      return;
    if (!current.empty())
      current.append("->");
    current.append(to_string(root->val));
    if (root->left == nullptr && root->right == nullptr) {
      result.push_back(current);
      return;
    }
    if (root->left)
      helper(root->left, current, result);
    if (root->right)
      helper(root->right, current, result);
  }

 public:
  /**
    * @param root: the root of the binary tree
    * @return: all root-to-leaf paths
    */
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    string current;
    helper(root, current, result);
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

