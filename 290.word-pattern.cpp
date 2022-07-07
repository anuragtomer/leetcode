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
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iterator>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());
        unordered_map<char, string> forward_hash;
        unordered_map<string, char> backward_hash;
        int i = 0;
        for (auto word: pattern) {
            if (i >= results.size())
                return false;
            if (forward_hash.find(word) == forward_hash.end() && 
                backward_hash.find(results[i]) == backward_hash.end()) {
                forward_hash[word] = results[i];
                backward_hash[results[i]] = word;
                i++;
            } else {
                if (forward_hash.find(word) != forward_hash.end() &&
                    forward_hash[word].compare(results[i]) != 0)
                    return false;
                if (backward_hash.find(results[i]) != backward_hash.end() &&
                    to_string(backward_hash[results[i]]).compare(to_string(word)) != 0)
                    return false;
                i++;
            }
        }
        return (i == results.size());
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