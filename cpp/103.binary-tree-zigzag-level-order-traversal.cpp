#include <algorithm>
#include <iostream>
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
    if (!root)
      return vector<vector<int>>();
    vector<TreeNode *> level = {root};
    vector<vector<int>> result;
    bool rev = false;
    int i = 0;
    while (i < level.size()) {
      int n = level.size();
      vector<int> row;
      while (i < n) {
        row.push_back(level[i]->val);
        if (level[i]->left)
          level.push_back(level[i]->left);
        if (level[i]->right)
          level.push_back(level[i]->right);
        ++i;
      }
      if (!row.empty()) {
        if (rev) {
          reverse(row.begin(), row.end());
          result.push_back(row);
        } else {
          result.push_back(row);
        }
        rev = !rev;
      }
    }
    return result;
  }
};
// Another solution
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    deque<TreeNode *> current, next;
    bool left_to_right = true;
    if (root)
      current.push_front(root);
    vector<vector<int>> result;
    vector<int> level;
    TreeNode *node = nullptr;
    while (not current.empty()) {
      node = current.front();
      current.pop_front();
      if (left_to_right) {
        if (node->left)
          next.push_front(node->left);
        if (node->right)
          next.push_front(node->right);
      } else {
        if (node->right)
          next.push_front(node->right);
        if (node->left)
          next.push_front(node->left);
      }
      level.push_back(node->val);
      if (current.empty()) {
        result.push_back(level);
        level.clear();
        current = next;
        next.clear();
        left_to_right = !left_to_right;
      }
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}
