#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
class TrieNode {
 public:
  int occurrence;
  char ch;
  unordered_map<char, shared_ptr<TrieNode>> child;
  bool is_end;

  TrieNode() : occurrence{0}, ch{'\0'}, is_end{false} {}
  TrieNode(int n, char ch_) : occurrence{n}, ch{ch_}, is_end{false} {}
};

class AutocompleteSystem {
  shared_ptr<TrieNode> root;
  shared_ptr<TrieNode> node;
  string current_state;

  void insert(string &input, int times);
  vector<string> findSentences(shared_ptr<TrieNode> &node, string &orig);

 public:
  AutocompleteSystem(vector<string> &sentences, vector<int> &times);
  vector<string> input(char c);
  void reset();
};

// Resets the state of the system. Any 'input' request will start finding from
// beginning and not where it left off.
void AutocompleteSystem::reset() {
  node = root;
  current_state.clear();
}

// Only constructor. Calls insert function to populate trie recursively for
// each input string.
AutocompleteSystem::AutocompleteSystem(vector<string> &sentences,
                                       vector<int> &times) {
  root = make_shared<TrieNode>();
  for (int i = 0; i < sentences.size(); ++i) {
    insert(sentences[i], times[i]);
  }
  node = root;
}

// Returns all the strings starting with c. Continues from where it left off in
// last input.
vector<string> AutocompleteSystem::input(char c) {
  if (node == nullptr || node->child[c] == nullptr)
    return {};
  node = node->child[c];
  current_state += c;
  return findSentences(node, current_state);
}

// Called by ctor. Fills up current string into trie.
void AutocompleteSystem::insert(string &input, int times) {
  auto temp = root;
  for (auto &ch : input) {
    if (temp->child.find(ch) == temp->child.end())
      temp->child[ch] = make_shared<TrieNode>(times, ch);
    else
      temp->child[ch]->occurrence = max(temp->child[ch]->occurrence, times);
    temp = temp->child[ch];
  }
  temp->is_end = true;
}

vector<string> AutocompleteSystem::findSentences(shared_ptr<TrieNode> &node,
                                                 string &orig) {
  vector<string> result;
  struct Data {
    shared_ptr<TrieNode> root;
    string current_string;
  };
  auto comp = [&](Data &a, Data &b) {
    if (a.root->occurrence == b.root->occurrence)
      return a.current_string > b.current_string;
    return a.root->occurrence <
           b.root->occurrence; // Sorting by occurrence count.
  };
  priority_queue<Data, vector<Data>, decltype(comp)> pq_current(comp);

  vector<string> resultSet;
  pq_current.push({node, orig});
  while (not pq_current.empty()) {
    auto [node, current] = pq_current.top();
    pq_current.pop();
    if (node->is_end) {
      resultSet.push_back(current);
      if (resultSet.size() == 3)
        break;
    }
    auto current_str = current;
    for (auto &child : node->child) {
      current_str.push_back(child.first);
      pq_current.push({child.second, current_str});
      current_str.pop_back();
    }
  }
  return resultSet;
}

int main() {
  auto lMatchOutputExpectation = [](vector<string> &exp,
                                    vector<string> &out) -> bool {
    if (exp.size() != out.size())
      return false;
    for (int i = 0; i < exp.size(); ++i) {
      if (exp[i] != out[i])
        return false;
    }
    return true;
  };
  vector<string> sentences = {"i love you", "island", "iroman",
                              "i love leetcode"};
  vector<int> times = {5, 3, 2, 2};
  AutocompleteSystem acs(sentences, times);
  vector<string> expected = {"i love you", "island", "i love leetcode"};
  vector<string> output = acs.input('i');
  assert(lMatchOutputExpectation(expected, output));
  expected = {"i love you", "i love leetcode"};
  output = acs.input(' ');
  assert(lMatchOutputExpectation(expected, output));
  expected = {};
  output = acs.input('a');
  assert(lMatchOutputExpectation(expected, output));
  expected = {};
  output = acs.input('#');
  assert(lMatchOutputExpectation(expected, output));
  cout << "All test cases passed.";
  return 0;
}

