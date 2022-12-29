#include <iostream>
#include <queue>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;

class Solution {
  int divide(vector<int> &nums, int beg, int end, int target) {
    for (int i = beg; i <= end; i++) {
      if (nums[i] > target)
        return i;
    }
    return end + 1;
  }
  TreeNode *create_tree(vector<int> &preorder, int beg, int end) {
    // cout << "Creating tree from " << beg << " to " << end << endl;
    if (beg < end) {
      int pivot = divide(preorder, beg + 1, end, preorder[beg]);
      TreeNode *root = new TreeNode(preorder[beg]);
      root->left = create_tree(preorder, beg + 1, pivot - 1);
      root->right = create_tree(preorder, pivot, end);
      return root;
    }
    if (beg == end) {
      return new TreeNode(preorder[beg]);
    }
    return nullptr;
  }

 public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    return create_tree(preorder, 0, preorder.size() - 1);
  }
};

void print_tree(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *front = q.front();
    if (front == nullptr)
      cout << "null ";
    else
      cout << front->val << " ";
    q.pop();
    if (front && (front->left != nullptr || front->right != nullptr)) {
      q.push(front->left);
      q.push(front->right);
    }
  }
}

int main() {
  Solution sol;
  vector<int> nums = {8, 5, 1, 7, 10, 12};
  trees::print_tree(sol.bstFromPreorder(nums));
  cout << "\n";
  nums = {4, 2};
  trees::print_tree(sol.bstFromPreorder(nums));
  return 0;
}