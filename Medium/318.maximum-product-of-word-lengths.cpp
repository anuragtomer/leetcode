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
        unordered_map<int, int> bitMaps;
        for (auto word : words) {
            int bitmap = 0;
            for (auto ch : word) {
                bitmap = bitmap | (1 << (ch - 'a'));
            }
            bitMaps[bitmap] = max(bitMaps[bitmap], static_cast<int>(word.size()));
        }
        int maxLen = 0;
        for (auto it : bitMaps) {
            for (auto it2 : bitMaps) {
                if (!(it.first & it2.first)) {
                    maxLen = max(maxLen, it.second * it2.second);
                }
            }
        }
        return maxLen;
    }
};
int main() {
    Solution sol;

    return 0;
}

