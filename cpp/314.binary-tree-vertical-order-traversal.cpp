#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
    map<int, map<int, multiset<int>>> levels;
    queue<pair<TreeNode *, pair<int, int>>> bfs;
    if (root)
      bfs.push({root, {0, 0}});
    while (!bfs.empty()) {
      auto node = bfs.front().first;
      auto [lev, height] = bfs.front().second;
      bfs.pop();
      levels[lev][height].insert(node->val);
      if (node->left)
        bfs.push({node->left, {lev - 1, height + 1}});
      if (node->right)
        bfs.push({node->right, {lev + 1, height + 1}});
    }
    vector<vector<int>> result;
    for (auto it : levels) {
      vector<int> column;
      for (auto c : it.second)
        copy(c.second.begin(), c.second.end(), back_inserter(column));
      result.push_back(column);
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

