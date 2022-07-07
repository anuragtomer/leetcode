#include <algorithm>
#include <iostream>
#include <unordered_map>
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
  void helper(TreeNode *root, int targetSum, int currentSum, int &count, unordered_map<int, int> &hash) {
    if (!root)
      return;
    currentSum += root->val;
    if (hash.find(currentSum - targetSum) != hash.end())
      count += hash[currentSum - targetSum];
    hash[currentSum]++;
    helper(root->left, targetSum, currentSum, count, hash);
    helper(root->right, targetSum, currentSum, count, hash);
    hash[currentSum]--;
    return;
  }

 public:
  int pathSum(TreeNode *root, int targetSum) {
    int count = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    helper(root, targetSum, 0, count, hash);
    return count;
  }
};
int main() {
  Solution sol;

  return 0;
}

