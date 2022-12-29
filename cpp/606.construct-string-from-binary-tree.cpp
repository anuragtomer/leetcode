#include <cassert>
#include <string>
#include "lib.hpp"
using namespace std;
using namespace trees;
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

int main() {
  Solution sol;
  TreeNode *root = create_tree("1,2,3,4", ',');
  assert("1(2(4))(3)" == sol.tree2str(root));
  delete_tree(root);
  root = create_tree("1,2,3,null,4", ',');
  assert("1(2()(4))(3)" == sol.tree2str(root));
  delete_tree(root);
  return 0;
}
