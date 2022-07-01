/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * Example 1:
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * Example 2:
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * Note:
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  bool allZero(vector<int> num) {
    for (auto elem : num) {
      if (elem != 0)
        return false;
    }
    return true;
  }

 public:
  /*
     * Algo:
     * 1. First make an array stating which chars appeared how many times in s1.
     * 2. Maintain a sliding window over the s2 which decrements the count in array 
     *    made in step 1. Also increment the count of elements which are going out of window.
     * 3. Keep checking if the array is all zero at any point of time. If so, return true.
     */
  /* bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    vector<int> num(26, 0);
    vector<int> zeros(26, 0);
    int i = 0;
    for (; i < s1.size(); i++) {
      num[s1[i] - 'a']++;
      num[s2[i] - 'a']--;
    }
    if (equal(num.begin(), num.end(), zeros.begin()))
      return true;
    for (; i < s2.size(); i++) {
      num[s2[i] - 'a']--;
      num[s2[i - s1.size()] - 'a']++;
      if (equal(num.begin(), num.end(), zeros.begin()))
        return true;
    }
    return false;
  }*/
  /* Better approach*/
  bool checkInclusion(string s1, string s2) {
    int map[26];
    memset(map, 0, sizeof(int) * 26);
    for (char &c : s1)
      ++map[c - 'a']; // Initialize the map with s1 characters
    int left = 0, count_chars = s1.size();
    for (int right = 0; right < s2.size(); ++right) {
      --map[s2[right] - 'a'];              // Account for this char from s2.
      if (map[s2[right] - 'a'] >= 0)       // Was above accounting valid? Were there enough s1 character?
        --count_chars;                     // Yes it was a valid match.
      if (count_chars == 0)                // Have I matched all chars of s1?
        return true;                       // Yes I have.
      if (right - left + 1 == s1.size()) { // Have I accounted for more characters than in s1?
        if (map[s2[left] - 'a'] >= 0)      // Did I match all chars of leftmost char?
          ++count_chars;
        ++map[s2[left] - 'a']; // Sliding window. Put char back in map from left.
        ++left;                // Increase left.
      }
    }
    return false;
  }
  // Similar to above but with lesser putting into map and popping back
    bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size())
      return false;
    if (s1.empty())
      return true;
    int pendingMatches = s1.size();
    vector<int> counts1(128, 0), counts2(128, 0);
    for (auto &ch: s1)
      counts1[ch]++;
    for (int i = 0, n = s1.size(); i < s2.size(); ++i) {
      if (i >= n && counts1[s2[i - n]] > 0) {
        --counts2[s2[i - n]];
        if (counts2[s2[i - n]] < counts1[s2[i - n]])
          ++pendingMatches;
      }
      if (counts1[s2[i]] > 0) {
        counts2[s2[i]]++;
        if (counts2[s2[i]] <= counts1[s2[i]])
          --pendingMatches;
      }
      if (pendingMatches == 0)
        return true;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution sol;
  string s1 = "ab", s2 = "eidbaooo";
  assert(true == sol.checkInclusion(s1, s2));
  s1 = "ab", s2 = "eidboaoo";
  assert(false == sol.checkInclusion(s1, s2));
  return 0;
}
/*
int main() {
    Solution sol;
    string s1, s2;
    cin >> s1;
    cin.ignore();
    cin >> s2;
    cout << boolalpha << sol.checkInclusion(s1, s2) << "\n";
    return 0;
}*/
