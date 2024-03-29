#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*class Solution {
  bool match(string word, string &pattern) {
    if (word.size() != pattern.size())
      return false;
    unordered_map<char, char> pTow;
    unordered_map<char, char> wTop;
    for (int i = 0; i < word.size(); ++i) {
      if (pTow.find(pattern[i]) == pTow.end()) {
        if (wTop.find(word[i]) != wTop.end())
          return false;
        pTow[pattern[i]] = word[i];
        wTop[word[i]] = pattern[i];
      } else {
        if (pTow[pattern[i]] != word[i] || wTop[word[i]] != pattern[i])
          return false;
      }
    }
    return true;
  }

 public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> result;
    for (auto word : words) {
      if (match(word, pattern))
        result.push_back(word);
    }
    return result;
  }
};*/
// Another solution
class Solution {
  string normalize(const string &word) {
    string replacedString;
    replacedString.reserve(word.size());
    char current = 'a';
    unordered_map<char, char> seen;
    for (auto &ch : word) {
      if (seen.find(ch) == seen.end()) {
        seen[ch] = current++;
      }
      replacedString.push_back(seen[ch]);
    }
    return replacedString;
  }

 public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> result;
    pattern = normalize(pattern);
    for (auto &word : words) {
      string replaced = normalize(word);
      if (replaced == pattern)
        result.push_back(word);
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}
