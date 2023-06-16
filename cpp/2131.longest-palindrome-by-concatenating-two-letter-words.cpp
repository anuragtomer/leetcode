#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> rev_words;
    int result = 0;
    string palin_word;
    for (auto &word : words) {
      if (rev_words[word] > 0) {
        result += 2 * word.size();
        --rev_words[word];
      } else {
        auto rev = word;
        reverse(rev.begin(), rev.end());
        ++rev_words[rev];
      }
    }
    size_t max_palin_word_size = 0;
    for (auto [word, count] : rev_words) {
      if (count == 0)
        continue;
      auto rev = word;
      reverse(rev.begin(), rev.end());
      if (rev == word) {
        max_palin_word_size = max(max_palin_word_size, word.size());
      }
    }
    return result + max_palin_word_size;
  }
};

int main() {
  Solution sol;
  vector<string> words = {"lc", "cl", "gg"};
  assert(sol.longestPalindrome(words) == 6);
  words = {"ab", "ty", "yt", "lc", "cl", "ab"};
  assert(sol.longestPalindrome(words) == 8);
  words = {"cc", "ll", "xx"};
  assert(sol.longestPalindrome(words) == 2);
  words = {"qo", "fo", "fq", "qf", "fo", "ff", "qq", "qf",
           "of", "of", "oo", "of", "of", "qf", "qf", "of"};
  assert(sol.longestPalindrome(words) == 14);
  return 0;
}
