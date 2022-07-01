#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
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
    this->left = this->right = NULL;
  }
};

class Solution {
 public:
  /**
    * @param root: the root of tree
    * @return: the vertical order traversal
    */
  vector<vector<int>> verticalOrder(TreeNode *root) {
    map<int, vector<int>> hash;
    queue<pair<TreeNode *, int>> level;
    level.push({root, 0});
    while (!level.empty()) {
      TreeNode *current = level.front().first;
      int lev = level.front().second;
      level.pop();
      if (current) {
        hash[lev].push_back(current->val);
        if (current->left) {
          level.push({current->left, lev - 1});
        }
        if (current->right) {
          level.push({current->right, lev + 1});
        }
      }
    }
    vector<vector<int>> result;
    for (auto it : hash) {
      result.push_back(it.second);
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

