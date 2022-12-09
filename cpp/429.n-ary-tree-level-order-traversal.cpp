#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;
    queue<Node *> nodes;
    if (root)
      nodes.push(root);
    while (not nodes.empty()) {
      result.push_back(vector<int>());
      int n = nodes.size();
      while (n-- > 0) {
        Node *current = nodes.front();
        nodes.pop();
        result.back().push_back(current->val);
        for (auto child : current->children)
          nodes.push(child);
      }
    }
    return result;
  }
};

void deleteTree(Node *root) {
  if (root) {
    for (auto child : root->children)
      deleteTree(child);
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
  Node *root = new Node(1);
  root->children.push_back(new Node(3));
  root->children.push_back(new Node(2));
  root->children.push_back(new Node(4));
  root->children[0]->children.push_back(new Node(5));
  root->children[0]->children.push_back(new Node(6));
  vector<vector<int>> expected = {{1}, {3, 2, 4}, {5, 6}};
  Solution sol;
  vector<vector<int>> output = sol.levelOrder(root);
  assert(lmatch(expected, output));
  deleteTree(root);
  root = new Node(1);
  root->children.push_back(new Node(2));
  root->children.push_back(new Node(3));
  root->children.push_back(new Node(4));
  root->children.push_back(new Node(5));
  root->children[1]->children.push_back(new Node(6));
  root->children[1]->children.push_back(new Node(7));
  root->children[2]->children.push_back(new Node(8));
  root->children[3]->children.push_back(new Node(9));
  root->children[3]->children.push_back(new Node(10));
  root->children[1]->children[1]->children.push_back(new Node(11));
  root->children[2]->children[0]->children.push_back(new Node(12));
  root->children[3]->children[0]->children.push_back(new Node(13));
  root->children[1]->children[1]->children[0]->children.push_back(new Node(14));
  expected = {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}};
  output = sol.levelOrder(root);
  assert(lmatch(expected, output));
  deleteTree(root);
  return 0;
}
