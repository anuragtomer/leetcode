#include <queue>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;
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
int main() {
  Solution sol;
  auto root = create_tree("1,7,0,7,8");
  assert(2 == sol.maxLevelSum(root));
  delete_tree(root);
  return 0;
}
