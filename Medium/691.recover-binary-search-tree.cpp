#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  void inorderTraversal(TreeNode *root) {
    if (!root)
      return;
    inorderTraversal(root->left);
    if (firstElement == nullptr && prevElement && prevElement->val >= root->val)
      firstElement = prevElement;
    if (firstElement != nullptr && prevElement && prevElement->val >= root->val)
      secondElement = root;
    prevElement = root;
    inorderTraversal(root->right);
  }
  TreeNode *firstElement = nullptr, *secondElement = nullptr, *prevElement = nullptr;

 public:
  /**
     * @param root: the given tree
     * @return: the tree after swapping
     */
  TreeNode *recoverTree(TreeNode *root) {
    inorderTraversal(root);
    if (firstElement != nullptr && secondElement != nullptr) {
      int temp = firstElement->val;
      firstElement->val = secondElement->val;
      secondElement->val = temp;
    }
    return root;
  }
};
int main() {
  Solution sol;

  return 0;
}

