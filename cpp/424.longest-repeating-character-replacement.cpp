#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int longest = 0, most_frequent = 0;
    vector<int> count(256, 0);
    for (int i = 0, n = s.size(), j = 0; i < n; ++i) {
      count[s[i]]++;
      most_frequent = max(most_frequent, count[s[i]]);
      while (i - j + 1 - most_frequent > k) {
        /**
         * This means that if the difference between 'Length of the current
         * substring' and 'Most occurred char' is greater than 'Max chars we
         * can replace', then we need to start excluding the chars in our
         * substring from beginning. */
        count[s[j]]--;
        j++;
      }
      longest = max(longest, i - j + 1);
    }
    return longest;
  }
};

int main() {
  Solution sol;
  string s;
  int k;
  s = "ABAB", k = 2;
  assert(4 == sol.characterReplacement(s, k));
  s = "AABABBA", k = 1;
  assert(4 == sol.characterReplacement(s, k));
  s = "AABAABBAAAAABAA", k = 1;
  assert(8 == sol.characterReplacement(s, k));
  return 0;
}
