#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Definition of TreeNode:*/
class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = nullptr;
  }
};

class Solution {
 public:
  /**
    * @param root: a binary search tree
    * @return: Root of a tree
    */
  TreeNode *increasingBST(TreeNode *root) { //, TreeNode *tail = nullptr) {
    TreeNode dummy(0);
    TreeNode *pre = &dummy;
    stack<TreeNode *> st;
    while (root || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      root = st.top();
      st.pop();
      pre->right = root;
      pre = pre->right;
      root->left = nullptr;
      root = root->right;
    }
    return dummy.right;
    /*
    if (!root) 
      return tail;
    TreeNode *result = increasingBST(root->left, root);
    root->left = nullptr;
    root->right = increasingBST(root->right, tail);
    return result;
    */
  }
};

int main() {
  Solution sol;
  (void)sol;
  return 0;
}

