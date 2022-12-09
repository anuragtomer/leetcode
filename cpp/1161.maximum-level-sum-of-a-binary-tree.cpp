#include <queue>
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
  int maxLevelSum(TreeNode *root) {
    if (!root)
      return 0;
    queue<TreeNode *> levels;
    if (root)
      levels.push(root);
    int maxSum = INT_MIN, smallest = 1;
    int level = 0;
    while (not levels.empty()) {
      int i = levels.size(), sum = 0;
      ++level;
      while (i > 0) {
        --i;
        auto node = levels.front();
        levels.pop();
        sum += node->val;
        if (node->left)
          levels.push(node->left);
        if (node->right)
          levels.push(node->right);
      }
      if (sum > maxSum) {
        maxSum = sum;
        smallest = level;
      }
    }
    return smallest;
  }
};
void deleteTree(TreeNode *root) {
  if (root) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
  }
}
int main() {
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);
  assert(2 == sol.maxLevelSum(root));
  deleteTree(root);
  return 0;
}

