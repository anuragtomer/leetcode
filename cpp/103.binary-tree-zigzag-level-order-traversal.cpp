#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    stack<TreeNode *> current, next;
    bool left_to_right = true;
    if (root)
      current.push(root);
    vector<vector<int>> result;
    vector<int> level;
    TreeNode *node = nullptr;
    while (not current.empty()) {
      node = current.top();
      current.pop();
      if (left_to_right) {
        if (node->left)
          next.push(node->left);
        if (node->right)
          next.push(node->right);
      } else {
        if (node->right)
          next.push(node->right);
        if (node->left)
          next.push(node->left);
      }
      level.push_back(node->val);
      if (current.empty()) {
        result.push_back(level);
        level.clear();
        swap(current, next);
        left_to_right = !left_to_right;
      }
    }
    return result;
  }
};

int main() {
  auto lMatch = [](vector<vector<int>> out, vector<vector<int>> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i].size() != exp[i].size())
        return false;
      for (int j = 0; j < out[i].size(); ++j)
        if (out[i][j] != exp[i][j])
          return false;
    }
    return true;
  };
  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  vector<vector<int>> expected = {{3}, {20, 9}, {15, 7}};
  assert(lMatch(sol.zigzagLevelOrder(root), expected));
  cout << "Passed.";
  return 0;
}
