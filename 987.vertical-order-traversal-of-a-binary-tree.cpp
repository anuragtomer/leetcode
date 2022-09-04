#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};
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

void deleteTree(TreeNode *root) {
  if (root) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
  }
}

int main() {
  auto lmatch = [](vector<vector<int>> &exp, vector<vector<int>> &out) {
    if (exp.size() != out.size())
      return false;
    for (int i = 0; i < exp.size(); ++i) {
      if (exp[i].size() != out[i].size())
        return false;
      for (int j = 0; j < exp[i].size(); ++j)
        if (exp[i][j] != out[i][j])
          return false;
    }
    return true;
  };

  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  vector<vector<int>> expected = {{9}, {3, 15}, {20}, {7}};
  vector<vector<int>> output = sol.verticalTraversal(root);
  assert(lmatch(output, expected));
  deleteTree(root);
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  expected = {{4}, {2}, {1, 5, 6}, {3}, {7}};
  output = sol.verticalTraversal(root);
  assert(lmatch(output, expected));
  deleteTree(root);
  root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(2);
  expected = {{0}, {1}, {3, 2, 2}, {4}};
  output = sol.verticalTraversal(root);
  assert(lmatch(output, expected));
  deleteTree(root);
  return 0;
}
