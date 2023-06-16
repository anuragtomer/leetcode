#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string findLongestWord(string s, vector<string> &dictionary) {
    sort(dictionary.begin(), dictionary.end(),
         [](string &existing, string &incoming) {
           if (incoming.size() == existing.size())
             return incoming > existing;
           return incoming.size() < existing.size();
         });
    string result;
    for (auto &word : dictionary) {
      int i = 0;
      for (int j = 0; i < word.size() && j < s.size(); ++j) {
        if (word[i] == s[j])
          ++i;
      }
      if (i == word.size()) {
        return word;
      }
    }
    return "";
  }
};
int main() {
  Solution sol;
  vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
  assert("apple" == sol.findLongestWord("abpcplea", dictionary));
  dictionary = {"a", "b", "c"};
  assert("a" == sol.findLongestWord("abpcplea", dictionary));
  return 0;
}
