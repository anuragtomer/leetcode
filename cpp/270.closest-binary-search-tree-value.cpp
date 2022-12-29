#include <cmath>

#include "lib.hpp"
using namespace std;
using namespace trees;
class Solution {
 public:
  int closestValue(TreeNode *root, double target) {
    auto delta = [&](int val) -> double {
      return fabs(target - static_cast<double>(val));
    };
    if (!root) {
      return INT_MAX;
    }
    if (root->val == target) {
      return root->val;
    } else if (target < root->val) {
      int left_ans = closestValue(root->left, target);
      if (delta(root->val) < delta(left_ans))
        return root->val;
      else
        return left_ans;
    } else {
      int right_ans = closestValue(root->right, target);
      if (delta(root->val) < delta(right_ans))
        return root->val;
      else
        return right_ans;
    }
  }
};

int main() {
  Solution sol;
  auto root = trees::create_tree("5,4,9,2,null,8,10");
  assert(sol.closestValue(root, 6.12478) == 5);
  trees::delete_tree(root);
  root = trees::create_tree("3,2,4,1");
  assert(sol.closestValue(root, 4.142857) == 4);
  trees::delete_tree(root);
  return 0;
}
