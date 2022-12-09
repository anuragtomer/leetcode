#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int count[26];
    fill_n(count, 26, 0);
    for (auto &ch : magazine)
      ++count[ch - 'a'];
    for (auto &ch : ransomNote) {
      if (count[ch - 'a'] <= 0)
        return false;
      --count[ch - 'a'];
    }
    return true;
  }
};

int main() {
  Solution sol;
  assert(sol.canConstruct("a", "a"));
  assert(sol.canConstruct("aa", "aab"));
  assert(not sol.canConstruct("abc", "acd"));
  return 0;
}
