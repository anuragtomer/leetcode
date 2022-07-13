#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> t_hash, s_hash;
    for (auto ch : t)
      t_hash[ch]++;
    int min_left = -1, min_len = INT_MAX, matched_chars = 0;
    for (int right = 0, left = 0; right < s.size(); ++right) {
      if (t_hash.find(s[right]) != t_hash.end()) {
        s_hash[s[right]]++;
        if (s_hash[s[right]] <= t_hash[s[right]])
          ++matched_chars;
      }
      if (matched_chars >= t.size()) {
        // We have matched all the chars of t
        while (t_hash.find(s[left]) == t_hash.end() ||
               t_hash[s[left]] < s_hash[s[left]]) {
          // Current
          s_hash[s[left]]--;
          ++left;
        }
        if (min_len > right - left + 1) {
          min_len = right - left + 1;
          min_left = left;
        }
      }
    }
    return min_left == -1 ? "" : s.substr(min_left, min_len);
  }
};

int main() {
  Solution sol;
  string s = "ADOBECODEBANC", t = "ABC";
  assert(sol.minWindow(s, t) == "BANC");

  s = "a", t = "a";
  assert(sol.minWindow(s, t) == "a");

  s = "bba", t = "ba";
  assert(sol.minWindow(s, t) == "ba");

  return 0;
}
