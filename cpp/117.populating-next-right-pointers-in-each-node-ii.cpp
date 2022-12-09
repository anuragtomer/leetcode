#include <cassert>
#include <functional>
using namespace std;

class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
    : val(_val), left(_left), right(_right), next(_next) {}
};
/*
 * Solution 1 using extra datastructures(queue)
class Solution {
   public:
    queue<Node *> q1, q2;

   public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;
        q1.push(root);
        Node *last = nullptr;
        while (!q1.empty()) {
            auto current = q1.front();
            if (last != nullptr)
                last->next = current;
            q1.pop();
            if (current->left)
                q2.push(current->left);
            if (current->right)
                q2.push(current->right);
            if (q1.empty()) {
                q1.swap(q2);
                queue<Node *>().swap(q2);
                last = nullptr;
            } else
                last = current;
        }
        return root;
    }
};
*/
// Another solution without using datastructures.
class Solution {
 public:
  Node *connect(Node *root) {
    if (root) {
      if (root->left && root->right)
        root->left->next = root->right;
      auto next = root->next;
      while (next && next->left == nullptr && next->right == nullptr)
        next = next->next;
      if (next) {
        if (root->right)
          root->right->next = next->left ? next->left : next->right;
        else if (root->left)
          root->left->next = next->left ? next->left : next->right;
      }
      root->right = connect(root->right);
      root->left = connect(root->left);
    }
    return root;
  }
};
int main() {
  Solution sol;
  std::function<void(Node *)> ldeleteTree = [&](Node *root) -> void {
    if (root) {
      ldeleteTree(root->left);
      ldeleteTree(root->right);
      delete root;
      root = nullptr;
    }
  };
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(7);
  root = sol.connect(root);
  assert(root->next == nullptr);
  assert(root->left->next == root->right);
  assert(root->right->next == nullptr);
  assert(root->left->left->next == root->left->right);
  assert(root->left->right->next == root->right->right);
  assert(root->right->right->next == nullptr);
  ldeleteTree(root);
  return 0;
}

