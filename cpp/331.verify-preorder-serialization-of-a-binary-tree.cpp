#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool root_null = false;
  bool pruneTree(vector<string> &tree) {
    if (tree.empty())
      return false;
    if (tree.size() == 1) {
      if (tree[0] == "#")
        root_null = true;
      return true;
    };
    int n = tree.size();
    if (tree[n - 1] == "#" && tree[n - 2] == "#") {
      if (n < 3)
        return false;
      tree.pop_back();
      tree.pop_back();
      if (tree.back() == "#")
        return false;
      tree.pop_back();
      tree.push_back("#");
      return pruneTree(tree);
    }
    return true;
  }

 public:
  bool isValidSerialization(string preorder) {
    vector<string> tree;
    string word;
    stringstream ss(preorder);
    while (getline(ss, word, ',')) {
      if (root_null)
        return false;
      tree.push_back(word);
      if (not pruneTree(tree))
        return false;
    }
    return tree.size() == 1 && tree[0] == "#";
  }
};

int main() {
  Solution sol;
  assert(sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
  assert(not sol.isValidSerialization("1,#"));
  assert(not sol.isValidSerialization("9,#,#,1"));
  cout << "All test cases passed.";
  return 0;
}
