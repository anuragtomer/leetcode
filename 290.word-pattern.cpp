/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms | Easy (35.73%)
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    unordered_map<string, char> stop;
    unordered_map<char, string> ptos;
    int i = 0;
    string word;
    while (getline(ss, word, ' ')) {
      if (i >= pattern.size())
        return false;
      char ch = pattern[i];
      ++i;
      if ((stop.find(word) == stop.end() && ptos.find(ch) != ptos.end()) ||
          stop.find(word) != stop.end() && ptos.find(ch) == ptos.end())
        return false;
      else if (stop.find(word) == stop.end() && ptos.find(ch) == ptos.end()) {
        stop[word] = ch;
        ptos[ch] = word;
      } else {
        if (stop[word] != ch || ptos[ch] != word)
          return false;
      }
    }
    return i == pattern.size();
  }
};
// @lc code=end

int main() {
  Solution sol;
  string pattern, str;
  cin >> pattern;
  cin.ignore();
  getline(cin, str);
  cout << boolalpha << sol.wordPattern(pattern, str);
  return 0;
}
