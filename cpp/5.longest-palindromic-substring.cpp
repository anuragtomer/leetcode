#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  pair<int, int> helper(string &s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
      --left;
      ++right;
    }
    ++left;
    --right;
    return {left /*start of palindrom*/,
            right - left + 1 /* Length of palindrom */};
  }

 public:
  string longestPalindrome(string s) {
    if (s.empty())
      return s;
    pair<int, int> longest = {0, 1};
    for (int i = 0, n = s.size(); i < n; ++i) {
      auto odd = helper(s, i, i, n);
      auto even = helper(s, i, i + 1, n);
      if (longest.second < odd.second)
        longest = odd;
      if (longest.second < even.second)
        longest = even;
    }
    return s.substr(longest.first, longest.second);
  }
};

int main() {
  Solution sol;
  assert("bab" == sol.longestPalindrome("babad"));
  return 0;
}
