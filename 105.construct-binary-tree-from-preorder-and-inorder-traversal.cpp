#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  TreeNode *helper(vector<int> &preorder, int &idx, vector<int> &inorder,
                   int lb, int ub) {
    if (lb > ub)
      return nullptr;
    TreeNode *node = nullptr;
    for (int i = lb; i <= ub; ++i) {
      if (inorder[i] == preorder[idx]) {
        node = new TreeNode(preorder[idx]);
        ++idx;
        node->left = helper(preorder, idx, inorder, lb, i - 1);
        node->right = helper(preorder, idx, inorder, i + 1, ub);
        return node;
      }
    }
    return node;
  }

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int idx = 0;
    return helper(preorder, idx, inorder, 0, inorder.size() - 1);
  }
};

int main() {
  Solution sol;

  return 0;
}
