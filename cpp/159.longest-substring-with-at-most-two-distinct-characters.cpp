#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> seen;
    int max_len = 0;
    for (int left = 0, right = 0; right < s.size(); ++right) {
      seen[s[right]]++;
      while (seen.size() > 2 && left < right) {
        --seen[s[left]];
        if (seen[s[left]] == 0) {
          seen.erase(s[left]);
        }
        ++left;
      }
      max_len = max(max_len, right - left + 1);
    }
    return max_len;
  }
};
int main() {
  Solution sol;
  assert(sol.lengthOfLongestSubstringTwoDistinct("eceba") == 3);
  assert(sol.lengthOfLongestSubstringTwoDistinct("ccaabbb") == 5);
  return 0;
}
