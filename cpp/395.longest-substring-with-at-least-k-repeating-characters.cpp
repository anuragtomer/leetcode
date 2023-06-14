#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestSubstring(string s, int k) {
    int n = s.size();
    if (n == 0 || n < k) {
      return 0;
    }
    if (k <= 1) {
      return n;
    }
    unordered_map<char, int> counts;
    for (auto ch : s) {
      ++counts[ch];
    }
    int left = 0;
    while (left < n && counts[s[left]] >= k) {
      ++left;
    }
    if (left >= n - 1) {
      return left;
    }
    int longest_left = longestSubstring(s.substr(0, left), k);
    while (left < n && counts[s[left]] < k) {
      ++left;
    }
    if (left >= n) {
      return longest_left;
    }
    int longest_right = longestSubstring(s.substr(left), k);
    return max(longest_left, longest_right);
  }
};

int main() {
  Solution sol;
  assert(3 == sol.longestSubstring("aaabb", 3));
  assert(5 == sol.longestSubstring("ababbc", 2));
  return 0;
}

