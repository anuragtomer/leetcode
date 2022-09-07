#include <cassert>
#include <string>
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
  string tree2str(TreeNode *root) {
    if (root == nullptr)
      return "";
    string result = to_string(root->val);
    string left = tree2str(root->left);
    string right = tree2str(root->right);
    if (not right.empty())
      result = result + '(' + left + ')' + '(' + right + ')';
    else if (not left.empty())
      result = result + '(' + left + ')';
    return result;
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
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  assert("1(2(4))(3)" == sol.tree2str(root));
  deleteTree(root);
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  assert("1(2()(4))(3)" == sol.tree2str(root));
  deleteTree(root);
  return 0;
}
