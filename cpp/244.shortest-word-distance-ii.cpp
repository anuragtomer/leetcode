#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class WordDistance {
  unordered_map<string, vector<vector<string>::iterator>> position;
  vector<string>::iterator end_it, begin_it;
  vector<string> words;

 public:
  WordDistance(vector<string> _words) {
    words = _words;
    for (auto it = words.begin(); it != words.end(); ++it) {
      position[*it].push_back(it);
    }
    end_it = words.end();
    begin_it = words.begin();
  }
  int shortest(string word1, string word2) {
    queue<vector<string>::iterator> bfs;
    for (auto its : position[word1]) {
      bfs.push(its);
    }
    int len = 0;
    while (not bfs.empty()) {
      int n = bfs.size();
      while (n) {
        --n;
        auto curr = bfs.front();
        bfs.pop();
        if (*curr == word2) {
          return len;
        }
        if (next(curr) != end_it) {
          bfs.push(next(curr));
        }
        if (curr != begin_it) {
          bfs.push(prev(curr));
        }
      }
      ++len;
    }
    return -1;
  }
};

int main() {
  vector<string> list = {"practice", "makes", "perfect", "coding", "makes"};
  WordDistance *wd = new WordDistance(list);
  assert(3 == wd->shortest("coding", "practice"));
  assert(1 == wd->shortest("makes", "coding"));
  cout << "Pass";
  return 0;
}
