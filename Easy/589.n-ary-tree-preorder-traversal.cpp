#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Node {
  int val;
  vector<Node *> children;
  Node() {}
  Node(int _val) : val(_val) {}
  Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};

class Solution {
 public:
  vector<int> preorder(Node *root) {
    vector<int> result;
    list<Node *> current_row;
    current_row.push_front(root);
    Node *current;
    while (not current_row.empty()) {
      current = current_row.front();
      current_row.pop_front();
      result.push_back(current->val);
      for (auto it = current->children.rbegin(); it != current->children.rend();
           ++it) {
        current_row.push_front(*it);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  Node *root = new Node(1);
  root->children = {new Node(3), new Node(2), new Node(4)};
  root->children[0]->children = {new Node(5), new Node(6)};
  vector<int> result = sol.preorder(root);
  for (auto &num : result)
    cout << num << " ";
  return 0;
}
