#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node *connect(Node *root) {
    if (!root || (!root->left && !root->right))
      return root;
    if (root->left && root->right)
      root->left->next = root->right;
    Node *sibling = root->next;
    while (sibling && !sibling->left && !sibling->right)
      sibling = sibling->next;
    if (sibling) {
      if (root->right)
        root->right->next = sibling->left ? sibling->left : sibling->right;
      else if (root->left)
        root->left->next = sibling->left ? sibling->left : sibling->right;
    }
    root->right = connect(root->right);
    root->left = connect(root->left);
    return root;
  }
};

int main() {
  Solution sol;

  return 0;
}

