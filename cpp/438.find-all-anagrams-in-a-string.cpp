#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
  bool theyMatch(vector<int> &p, vector<int> &s) {
    for (int i = 0; i < 26; ++i)
      if (p[i] != s[i])
        return false;
    return true;
  }

 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> pcounts(26, 0);
    for (int i = 0; i < p.size(); ++i)
      pcounts[p[i] - 'a']++;
    vector<int> scounts(26, 0);
    vector<int> result;
    int psize = p.size(), ssize = s.size();
    for (int i = 0; i < ssize; ++i) {
      if (pcounts[s[i] - 'a'] > 0) {
        scounts[s[i] - 'a']++;
      }
      if (i >= psize && pcounts[s[i - psize] - 'a'] > 0) {
        scounts[s[i - psize] - 'a']--;
      }
      if (theyMatch(scounts, pcounts)) {
        result.push_back(i - psize + 1);
      }
    }
    return result;
  }
};
*/
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    unordered_map<char, int> p_count;
    for (auto ch : p)
      p_count[ch]++;
    int chars_to_match = p_count.size();
    int psize = p.size(), left = 0, right = 0;
    while (right < s.size()) {
      if (p_count.find(s[right]) != p_count.end()) {
        p_count[s[right]]--;
        if (p_count[s[right]] == 0)
          --chars_to_match;
      }
      if (right - left + 1 < psize)
        ++right;
      else if (right - left + 1 == psize) {
        if (chars_to_match == 0)
          result.push_back(left);
        if (p_count.find(s[left]) != p_count.end()) {
          p_count[s[left]]++;
          if (p_count[s[left]] == 1)
            ++chars_to_match;
        }
        ++left;
        ++right;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> output = sol.findAnagrams("abab", "ab");
  vector<int> result = {0, 1, 2};
  assert(output.size() == result.size());
  for (int i = 0; i < result.size(); ++i)
    assert(output[i] == result[i]);
  output = sol.findAnagrams("cbaebabacd", "abc");
  result = {0, 6};
  assert(output.size() == result.size());
  for (int i = 0; i < output.size(); ++i)
    assert(output[i] == result[i]);
  return 0;
}
