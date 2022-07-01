#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
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
    * @param root: the binary tree of the  root
    * @return: return a list of double
    */
  vector<double> averageOfLevels(TreeNode *root) {
    unordered_map<int, pair<int, int>> hash;
    if (!root)
      return {};
    queue<pair<TreeNode *, int>> level;
    level.push({root, 0});
    while (level.empty() == false) {
      TreeNode *temp = level.front().first;
      int l = level.front().second;
      level.pop();
      if (hash.count(l)) {
        hash[l].first += temp->val;
        hash[l].second++;
      } else {
        hash[l].first = temp->val;
        hash[l].second = 1;
      }
      if (temp->left)
        level.push({temp->left, l + 1});
      if (temp->right)
        level.push({temp->right, l + 1});
    }
    vector<double> result(hash.size());
    for (int i = 0; i < hash.size(); ++i) {
      result[i] = static_cast<double>(hash[i].first) / static_cast<double>(hash[i].second);
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

