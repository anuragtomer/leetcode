#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  struct Node {
    bool is_file;
    string name;
    Node() { is_file = false; }
  };
  int countTabs(string &input, int &i) {
    int count = 0;
    while (i < input.size() && input[i] == '\t') {
      ++count;
      i += 1;
    }
    return count;
  }
  void computeLongest(int &longest, vector<Node *> &nodes, int pop_count) {
    if (nodes.back()->is_file) {
      int length = 0;
      for (auto n : nodes) {
        length += n->name.size();
        length++;
      }
      longest = max(longest, length - 1);
    }
    while (pop_count && not nodes.empty()) {
      auto node = nodes.back();
      delete node;
      nodes.pop_back();
      --pop_count;
    }
  }

 public:
  int lengthLongestPath(string input) {
    vector<pair<string, int>> entries;
    Node *node = new Node();
    vector<Node *> st;
    int tabs = 0;
    int longest = 0;
    for (int i = 0, n = input.size(); i <= n;) {
      if ((i < n && input[i] == '\n') || (i == n)) {
        i += 1;
        st.push_back(node);
        int tab_count = countTabs(input, i);
        if (tab_count <= tabs) {
          computeLongest(longest, st, tabs - tab_count + 1);
          node = new Node();
        } else {
          node = new Node();
        }
        tabs = tab_count;
      } else if (i < n) {
        if (input[i] == '.')
          node->is_file = true;
        node->name.push_back(input[i]);
        ++i;
      }
    }
    return longest;
  }
};

int main() {
  Solution sol;
  assert(sol.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") ==
         20);
  assert(sol.lengthLongestPath(
           "dir\n\tsubdir1\n\t\tfile1."
           "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") ==
         32);
  assert(sol.lengthLongestPath("a") == 0);
  cout << "All test cases passed.";
  return 0;
}

