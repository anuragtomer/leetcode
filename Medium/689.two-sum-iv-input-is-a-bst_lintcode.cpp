#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
  * Definition of TreeNode:*/
class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

class Solution {
  vector<int> helper(TreeNode *root, int n, unordered_set<int> &hash) {
    if (!root)
      return {};
    if (hash.find(n - root->val) != hash.end())
      return {root->val, n - root->val};
    hash.insert(root->val);
    vector<int> child = helper(root->left, n, hash);
    if (!child.empty())
      return child;
    child = helper(root->right, n, hash);
    if (!child.empty())
      return child;
    return {};
  }

 public:
  /*
    * @param : the root of tree
    * @param : the target sum
    * @return: two number from tree witch sum is n
    */
  vector<int> twoSum(TreeNode *root, int n) {
    unordered_set<int> hash;
    return helper(root, n, hash);
  }
};
/*
 O(1) space solution.
class Solution {
  vector<int> search(TreeNode *root, TreeNode *curr, int k) {
    if (!root)
      return {};
    if (root->val == k && root != curr)
      return {root->val};
    if (root->val < k) {
      return search(root->right, curr, k);
    }
    return search(root->left, curr, k);
  }
  vector<int> dfs(TreeNode *root, TreeNode *curr, int k) {
    if (curr == nullptr)
      return {};
    vector<int> child = search(root, curr, k - curr->val);
    if (!child.empty())
      return {child[0], curr->val};
    child = dfs(root, curr->left, k);
    if (!child.empty())
      return child;
    return dfs(root, curr->right, k);
  }
public:
  vector<int> twoSum(TreeNode * root, int n) {
    return dfs(root, root, n);
  }
};
*/
int main() {
  Solution sol;

  return 0;
}

