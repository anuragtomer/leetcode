#include <algorithm>
#include <iostream>
#include <vector>

#include "lib.hpp"

using namespace std;
using trees::TreeNode;

class Solution {
 public:
  bool isCompleteTree(TreeNode *root) {
    if (!root) {
      return true;
    }
    queue<TreeNode *> current;
    if (root) {
      current.push(root);
    }
    while (not current.empty()) {
      auto node = current.front();
      current.pop();
      if (node) {
        current.push(node->left);
        current.push(node->right);
      } else {
        // Current node is nullptr. None of the next nodes in current or next
        // queue should have any non-null nodes.
        while (not current.empty()) {
          auto node = current.front();
          current.pop();
          if (node != nullptr) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  std::cout << "Testcase 1: ";
  assert(sol.isCompleteTree(root));
  std::cout << "Passed" << endl;
  trees::delete_tree(root);
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  std::cout << "Testcase 2: ";
  assert(not sol.isCompleteTree(root));
  std::cout << "Passed" << endl;
  trees::delete_tree(root);
  return 0;
}
