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
        for (auto elem: num) {
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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> num(26, 0);
        int i = 0;
        for (; i < s1.size(); i++) {
            num[s1[i] - 'a']++;
            num[s2[i] - 'a']--;
        }
        if (allZero(num)) return true;
        for (; i < s2.size(); i++) {
            num[s2[i] - 'a']--;
            num[s2[i - s1.size()] - 'a']++;
            if (allZero(num)) return true;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s1, s2;
    cin >> s1;
    cin.ignore();
    cin >> s2;
    cout << boolalpha << sol.checkInclusion(s1, s2) << "\n";
    return 0;
}