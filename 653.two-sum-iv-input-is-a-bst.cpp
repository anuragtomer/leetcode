#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  bool helper(TreeNode *root, int n, unordered_set<int> &hash) {
    if (!root)
      return false;
    if (hash.find(n - root->val) != hash.end())
      return true;
    hash.insert(root->val);
    if (helper(root->left, n, hash))
      return true;
    if (helper(root->right, n, hash))
      return true;
    return false;
  }

 public:
  bool findTarget(TreeNode *root, int k) {
    unordered_set<int> hash;
    return helper(root, k, hash);
  }
};
int main() {
  Solution sol;

  return 0;
}

