#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*class Solution {
  bool noCommon(string &word1, string &word2, vector<int> &count) {
    for (auto ch: word2)
      if (count[ch - 'a'] > 0)
        return false;
    return true;
  }
  void fillMap(string &word, unordered_map<string, vector<int>> &map) {
    vector<int> count(26, 0);
    for (auto ch: word)
      count[ch - 'a']++;
    map[word] = count;
  }
public:
  int maxProduct(vector<string>& words) {
    unordered_map<string, vector<int>> map;
    for (auto word: words) {
      fillMap(word, map);
    }
    int maxProd = 0;
    for (int i = 0; i < words.size(); ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        if (noCommon(words[i], words[j], map[words[i]]))
          maxProd = max(maxProd, static_cast<int>(words[i].size() * words[j].size()));
      }
    }
    return maxProd;
  }
};*/
class Solution {
 public:
  int maxProduct(vector<string> &words) {
    unordered_map<bitset<26>, int> bitMaps;
    for (auto word : words) {
      bitset<26> bitmap;
      for (auto ch : word) {
        bitmap.set(ch - 'a');
      }
      bitMaps[bitmap] = max(bitMaps[bitmap], static_cast<int>(word.size()));
    }
    int maxLen = 0;
    for (auto [bit1, len1] : bitMaps) {
      for (auto [bit2, len2] : bitMaps) {
        if ((bit1 & bit2) == 0) {
          maxLen = max(maxLen, len1 * len2);
        }
      }
    }
    return maxLen;
  }
};
int main() {
  Solution sol;
  vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  assert(sol.maxProduct(words) == 16);
  words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  assert(sol.maxProduct(words) == 4);
  words = {"a", "aa", "aaa", "aaaa"};
  assert(sol.maxProduct(words) == 0);
  cout << "All test cases passed.";

  return 0;
}
