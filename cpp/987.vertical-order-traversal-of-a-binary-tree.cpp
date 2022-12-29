#include <map>
#include <queue>
#include <set>
#include <vector>
#include "lib.hpp"
using namespace std;
using namespace trees;
class Solution {
  void traverse(TreeNode *root, map<int, map<int, multiset<int>>> &order) {
    queue<pair<pair<TreeNode *, int>, int>> nodes;
    if (root)
      nodes.push({{root, 0}, 0});
    while (not nodes.empty()) {
      pair<pair<TreeNode *, int>, int> next = nodes.front();
      nodes.pop();
      int level = next.second, index = next.first.second;
      TreeNode *node = next.first.first;
      order[index][level].insert(node->val);
      if (node->left)
        nodes.push({{node->left, index - 1}, level + 1});
      if (node->right)
        nodes.push({{node->right, index + 1}, level + 1});
    }
  }

 public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, map<int, multiset<int>>> order;
    traverse(root, order);
    vector<vector<int>> result;
    for (auto it : order) {
      result.push_back(vector<int>());
      for (auto levels : it.second) {
        for (auto values : levels.second)
          result.back().push_back(values);
      }
    }
    return result;
  }
};

int main() {

  Solution sol;
  TreeNode *root;
  root = create_tree("3,9,20,null,null,15,7", ',');
  assert(vectors::match_unsorted_vecs(sol.verticalTraversal(root),
                                      {{9}, {3, 15}, {20}, {7}}));
  delete_tree(root);
  root = trees::create_tree("1,2,3,4,5,6,7", ',');
  assert(vectors::match_unsorted_vecs(sol.verticalTraversal(root),
                                      {{4}, {2}, {1, 5, 6}, {3}, {7}}));
  delete_tree(root);
  root = trees::create_tree("3,1,4,0,2,2", ',');
  assert(vectors::match_unsorted_vecs(sol.verticalTraversal(root),
                                      {{0}, {1}, {3, 2, 2}, {4}}));
  delete_tree(root);
  return 0;
}
