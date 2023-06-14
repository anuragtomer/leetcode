#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (root == nullptr) {
      return "#,";
    }
    string serialized;
    if (root) {
      serialized = to_string(root->val) + ",";
    }
    serialized += serialize(root->left);
    serialized += serialize(root->right);
    return serialized;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    stringstream ss(data);
    string word;
    vector<int> values;
    while (getline(ss, word, ',')) {
      if (word != "#" && not word.empty()) {
        values.push_back(stoi(word));
      }
    }
    if (values.empty())
      return nullptr;
    return createTree(values, 0, values.size());
  }

 private:
  TreeNode *createTree(vector<int> &values, int lb, int ub) {
    if (lb >= ub)
      return nullptr;
    TreeNode *root = new TreeNode(values[lb]);
    int mid = lb + 1;
    for (int i = lb + 1; i < ub; ++i) {
      if (values[i] < values[lb]) {
        ++mid;
      } else
        break;
    }
    root->left = createTree(values, lb + 1, mid);
    root->right = createTree(values, mid, ub);
    return root;
  }
};

int main() {
  Codec ser_deser;
  string input = "5,3,2,#,#,4,#,#,7,6,#,#,8,#,#,";
  assert(input == ser_deser.serialize(ser_deser.deserialize(input)));
  assert("1,#,#," == ser_deser.serialize(ser_deser.deserialize("1,#,#,")));
  assert("#," == ser_deser.serialize(ser_deser.deserialize("#,")));

  return 0;
}

