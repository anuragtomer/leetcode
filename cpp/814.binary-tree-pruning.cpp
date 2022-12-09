#include <cassert>
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
  bool pruneRoot(TreeNode *&root) {
    if (!root)
      return true;

    if (root->left && pruneRoot(root->left))
      root->left = nullptr;
    if (root->right && pruneRoot(root->right))
      root->right = nullptr;
    if (root->left == nullptr && root->right == nullptr && root->val == 0) {
      delete root;
      root = nullptr;
      return true;
    } else
      return false;
  }

 public:
  TreeNode *pruneTree(TreeNode *root) {
    if (root && pruneRoot(root)) {
      delete root;
      root = nullptr;
      return nullptr;
    } else
      return root;
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
  root->right = new TreeNode(0);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);
  root = sol.pruneTree(root);
  assert(root && root->val == 1);
  assert(root->left == nullptr);
  assert(root->right && root->right->val == 0);
  assert(root->right->right && root->right->right->val == 1);
  assert(root->right->left == nullptr);
  assert(root->right->right->left == nullptr &&
         root->right->right->right == nullptr);
  deleteTree(root);
  return 0;
}

