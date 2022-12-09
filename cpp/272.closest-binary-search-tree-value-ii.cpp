#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/**
 * Definition of TreeNode:
 */
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
  template <typename CompT>
  void helper(TreeNode *root, int k, priority_queue<int, vector<int>, CompT> &maxHeap) {
    if (!root)
      return;
    helper(root->left, k, maxHeap);
    maxHeap.push(root->val);
    if (maxHeap.size() > k)
      maxHeap.pop();
    helper(root->right, k, maxHeap);
  }

 public:
  vector<int> closestKValues(TreeNode *root, double target, int k) {
    auto comp = [&](int a, int b) { return fabs(target - a) < fabs(target - b); };

    priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);
    helper(root, k, maxHeap);
    vector<int> result;
    while (!maxHeap.empty()) {
      result.push_back(maxHeap.top());
      maxHeap.pop();
    }
    return result;
  }
};
int main() {
  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);
  vector<int> result = sol.closestKValues(root, 0.275, 2);
  for (auto res : result)
    cout << res << endl;
  return 0;
}

