#include <queue>
#include <unordered_map>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;

class Solution {
 public:
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
      result[i] = static_cast<double>(hash[i].first) /
                  static_cast<double>(hash[i].second);
    }
    return result;
  }
  vector<double> averageOfLevels2(TreeNode *root) {
    queue<TreeNode *> levels;
    if (root != nullptr)
      levels.push(root);
    vector<double> result;
    while (not levels.empty()) {
      int i = levels.size(), count = 0;
      double sum = 0.0;
      while (i > 0) {
        --i;
        ++count;
        auto node = levels.front();
        levels.pop();
        sum += node->val;
        if (node->left)
          levels.push(node->left);
        if (node->right)
          levels.push(node->right);
      }
      result.push_back(sum / count);
    }
    return result;
  }
};

int main() {
  auto lmatch = [](vector<double> &exp, vector<double> &res) -> bool {
    if (exp.size() != res.size())
      return false;
    for (int i = 0; i < exp.size(); ++i)
      if (res[i] != exp[i])
        return false;
    return true;
  };
  Solution sol;
  TreeNode *root;
  root = create_tree("3,9,20,null,null,15,7", ',');
  vector<double> expected = {3.0, 14.5, 11.0};
  vector<double> result = sol.averageOfLevels(root);
  assert(vectors::match_unsorted_vecs(expected, result));
  result = sol.averageOfLevels2(root);
  assert(vectors::match_unsorted_vecs(expected, result));
  delete_tree(root);
  return 0;
}
