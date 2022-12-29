#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  /* One way to do it */
  int shortestDistance2(vector<string> &words, string word1, string word2) {
    int i = -1, j = -1, minDistance = INT_MAX;
    for (int k = 0; k < words.size(); ++k) {
      if (words[k] == word1)
        i = k;
      else if (words[k] == word2)
        j = k;
      if (i != -1 && j != -1) minDistance = min(minDistance, abs(i - j));
    }
    if (i == -1 || j == -1)
      return -1;
    else
      return minDistance;
  }
  /* More geeky way */
  int shortestDistance(vector<string> &words, string word1, string word2) {
    unordered_map<string, vector<vector<string>::iterator>> position;
    for (auto it = words.begin(); it != words.end(); ++it) {
      position[*it].push_back(it);
    }
    queue<vector<string>::iterator> bfs;
    for (auto its : position[word1]) bfs.push(its);
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
        if (next(curr) != words.end()) bfs.push(next(curr));
        if (curr != words.begin()) bfs.push(prev(curr));
      }
      ++len;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<string> list = {"practice", "makes", "perfect", "coding", "makes"};

  assert(sol.shortestDistance(list, "coding", "practice") == 3);
  cout << "Pass 1" << endl;
  assert(sol.shortestDistance(list, "makes", "coding") == 1);
  cout << "Pass 2" << endl;

  assert(sol.shortestDistance2(list, "coding", "practice") == 3);
  cout << "Pass 1" << endl;
  assert(sol.shortestDistance2(list, "makes", "coding") == 1);
  cout << "Pass 2" << endl;

  return 0;
}
