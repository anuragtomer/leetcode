#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of TreeNode: */
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
     * @param root1: the first tree
     * @param root2: the second tree
     * @return: returns whether the leaf sequence is the same
     */
  void leafSequence(TreeNode *root, vector<int> &result) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      result.push_back(root->val);
      return;
    }
    leafSequence(root->left, result);
    leafSequence(root->right, result);
  }
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> sequenceOne, sequenceTwo;
    leafSequence(root1, sequenceOne);
    leafSequence(root2, sequenceTwo);
    if (sequenceOne.size() != sequenceTwo.size())
      return false;
    for (int i = 0; i < sequenceOne.size(); ++i)
      if (sequenceOne[i] != sequenceTwo[i])
        return false;
    return true;
  }
};
int main() {
  Solution sol;

  return 0;
}

