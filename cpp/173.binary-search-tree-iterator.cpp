#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BSTIterator {
  stack<TreeNode *> st;
  void populateStack(TreeNode *root) {
    while (root != nullptr) {
      st.push(root);
      root = root->left;
    }
  }

 public:
  BSTIterator(TreeNode *root) { populateStack(root); }

  int next() {
    if (st.empty() == true) {
      return -1;
    } else {
      TreeNode *tp = st.top();
      st.pop();
      if (tp->right)
        populateStack(tp->right);
      return tp->val;
    }
  }

  bool hasNext() { return !(st.empty()); }
};

int main() {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(11);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(12);
  BSTIterator it = BSTIterator(root);
  while (it.hasNext() == true)
    cout << it.next() << "\t";
  cout << "\n";
  return 0;
}
