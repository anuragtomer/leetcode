/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */
#include <cassert>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start

class Solution {
  void inorderTraversal(TreeNode *root, int k, int &i, int &result) {
    if (!root)
      return;
    if (i >= k)
      return;
    if (root->left)
      inorderTraversal(root->left, k, i, result);
    ++i;
    if (i == k)
      result = root->val;
    if (root->right)
      inorderTraversal(root->right, k, i, result);
    return;
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    int result = INT_MIN, i = 0;
    inorderTraversal(root, k, i, result);
    return result == INT_MIN ? -1 : result;
  }
};
// @lc code=end

int main(void) {
  Solution sol;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);
  int count = 0;
  int total = 6;
  for (int i = 1; i <= 6; ++i)
    if (i == sol.kthSmallest(root, i)) {
      count++;
    }
  cout << count << "/" << total << " test cases passed.\n";
  return 0;
}
