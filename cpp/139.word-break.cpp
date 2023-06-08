#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    vector<bool> matched(n + 1, false);
    matched[0] = true;
    unordered_set<string> set;
    for (int i = 0; i < wordDict.size(); i++)
      set.insert(wordDict[i]);

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = i - 1; j >= 0; j--) {
        if (matched[j] == true) {
          string str = s.substr(j, i - j);
          if (set.find(str) != set.end()) {
            matched[i] = true;
            break;
          }
        }
      }
    }
    return matched.back();
  }
};

int main() {
  Solution sol;
  vector<string> wordDict;
  wordDict = {"leet", "code"};
  assert(sol.wordBreak("leetcode", wordDict));
  wordDict = {"apple", "pen"};
  assert(sol.wordBreak("applepenapple", wordDict));
  wordDict = {"cats", "cat", "dog", "sand", "and"};
  assert(not sol.wordBreak("catsandog", wordDict));
  cout << "Passed.";
  return 0;
}
