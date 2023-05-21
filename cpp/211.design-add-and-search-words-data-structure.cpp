/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 * Design a data structure that supports the following two operations:
 * void addWord(word)
 * bool search(word)
 *
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or (.).
 * A (.) means it can represent any one letter.
 *
 * Example:
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 */

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// @lc code=start
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
  bool search(string word, Node *node) {
    if (root == nullptr)
      return false;
    for (int i = 0; i < word.size(); ++i) {
      char ch = word[i];
      if (ch == '.') {
        for (auto child : node->children) {
          if (child &&
              search(string(word.begin() + i + 1, word.end()), child)) {
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
  /** Initialize your data structure here. */
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
  /** Adds a word into the data structure. */
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

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) { return search(word, root); }
};

// @lc code=end

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
  cout << "all test cases passed.\n";
  return 0;
}
