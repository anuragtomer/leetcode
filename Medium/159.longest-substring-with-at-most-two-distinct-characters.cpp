#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
  int lengthOfLongestSubstringTwoDistinct(string &s) {
    unordered_map<char, int> count;
    int maxLen = 0;
    for (int left = 0, right = 0, n = s.size(); right < n; ++right) {
      count[s[right]]++;
      while (left < right && count.size() > 2) {
        count[s[left]]--;
        if (count[s[left]] == 0)
          count.erase(s[left]);
        ++left;
      }
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};
int main() {
  Solution sol;

  return 0;
}

