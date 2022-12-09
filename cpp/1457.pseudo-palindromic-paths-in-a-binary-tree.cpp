#include <bitset>
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
  int paths(TreeNode *root, bitset<10> &seen) {
    if (!root)
      return 0;
    seen.flip(root->val);
    int val = 0;
    if (root->left == nullptr && root->right == nullptr) {
      if (seen.count() == 0 || seen.count() == 1)
        val = 1;
      seen.flip(root->val);
      return val;
    }
    val = paths(root->left, seen) + paths(root->right, seen);
    seen.flip(root->val);
    return val;
  }

 public:
  int pseudoPalindromicPaths(TreeNode *root) {
    bitset<10> seen;
    return paths(root, seen);
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
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(3);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(1);
  assert(2 == sol.pseudoPalindromicPaths(root));
  deleteTree(root);
  root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->left->right->right = new TreeNode(1);
  assert(1 == sol.pseudoPalindromicPaths(root));
  deleteTree(root);
  root = new TreeNode(9);
  assert(1 == sol.pseudoPalindromicPaths(root));
  deleteTree(root);
  return 0;
}

