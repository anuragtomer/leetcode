#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class WordDictionary {
  struct Node {
    Node *children[26];
    bool is_end;
    Node() {
      is_end = false;
      for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
      }
    }
  };
  Node *root;
  bool searchHelper(string &word, Node *node, int idx) {
    if (root == nullptr)
      return false;
    for (; idx < word.size(); ++idx) {
      char ch = word[idx];
      if (ch == '.') {
        for (auto child : node->children) {
          if (child && searchHelper(word, child, idx + 1)) {
            return true;
          }
        }
        return false;
      } else if (!node->children[ch - 'a'])
        return false;
      node = node->children[ch - 'a'];
    }
    return node->is_end;
  }

 public:
  WordDictionary() { root = new Node(); }
  ~WordDictionary() {
    queue<Node *> all_nodes;
    all_nodes.push(root);
    while (not all_nodes.empty()) {
      Node *node = all_nodes.front();
      all_nodes.pop();
      for (int i = 0; i < 26; ++i) {
        if (node->children[i] != nullptr) {
          all_nodes.push(node->children[i]);
        }
      }
      delete node;
    }
  }
  void addWord(string word) {
    if (root == nullptr)
      return;
    Node *curr = root;
    for (auto ch : word) {
      if (!curr->children[ch - 'a']) {
        curr->children[ch - 'a'] = new Node();
      }
      curr = curr->children[ch - 'a'];
    }
    curr->is_end = true;
  }

  bool search(string word) { return searchHelper(word, root, 0); }
};

int main() {
  WordDictionary dictionary = WordDictionary();
  dictionary.addWord("bad");
  dictionary.addWord("dad");
  dictionary.addWord("mad");
  assert(dictionary.search("pad") == false);
  assert(dictionary.search("bad") == true);
  assert(dictionary.search(".ad") == true);
  assert(dictionary.search("b..") == true);
  assert(dictionary.search("b.p") == false);
  assert(dictionary.search("d..d") == false);
  cout << "All test cases passed.\n";
  return 0;
}
