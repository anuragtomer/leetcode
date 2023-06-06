#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
  TreeNode *helper(vector<int> &num, int start, int end) {
    if (start >= end)
      return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = helper(num, start, mid);
    root->right = helper(num, mid + 1, end);
    return root;
  }

 public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return helper(nums, 0, nums.size());
  }
};

bool lMatchTree(TreeNode *treeA, TreeNode *treeB) {
  if (treeA == nullptr)
    return treeB == nullptr;
  if (treeB == nullptr)
    return treeA == nullptr;
  return treeA->val == treeB->val && lMatchTree(treeA->left, treeB->left) &&
         lMatchTree(treeA->right, treeB->right);
}

int main() {
  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(-3);
  root->right = new TreeNode(9);
  root->left->left = new TreeNode(-10);
  root->right->left = new TreeNode(5);
  Solution sol;
  vector<int> nums = {-10, -3, 0, 5, 9};
  assert(lMatchTree(root, sol.sortedArrayToBST(nums)));
  cout << "All test cases passed.";
  return 0;
}
