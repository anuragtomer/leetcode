#include <algorithm>
#include <iostream>
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
    * @param root: root of a tree
    * @return: head node of a doubly linked list
    */
  TreeNode *treeToDoublyList(TreeNode *root) {
    if (!root)
      return root;
    TreeNode *first = nullptr, *last = nullptr;
    treeToDLL(root, first, last);
    first->left = last;
    last->right = first;
    return first;
  }

 private:
  void treeToDLL(TreeNode *root, TreeNode *&first, TreeNode *&last) {
    if (!root)
      return;
    treeToDLL(root->left, first, last);
    if (first == nullptr) {
      first = root;
      last = root;
    } else {
      last->right = root;
      root->left = last;
      last = root;
    }
    treeToDLL(root->right, first, last);
  }
};

int main() {
  Solution sol;

  return 0;
}

