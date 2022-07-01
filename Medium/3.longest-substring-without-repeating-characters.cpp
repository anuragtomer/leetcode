/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <cstring>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
/*  
    Working but O(n^2) solution.
    Takes 28ms to complete (better than 40% runtimes, 96.02% space usage)

    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        int stringSize = s.size();
        bool hash[256];
        int currSize = 0;
        for (int i = 0; i < stringSize; ++i) {
            memset(hash, false, 256);
            currSize = 0;
            for (int j = i;
                 j < stringSize && hash[s[j]] == false; j++) {
                hash[s[j]] = true;
                ++currSize;
            }
            maxSize = max(currSize, maxSize);
        }
        return max(maxSize, currSize);
    } */
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        memset(hash, -1, 256 * sizeof(int));
        int m = 0;
        int len = 0;
        int stringsize = s.size();
        for (int i = 0; i < stringsize; i++) {
            m = max(hash[s[i]] + 1, m);
            len = max(len, i - m + 1);
            hash[s[i]] = i;
        }
        return len;
    }
};
// @lc code=end

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s);
    return 0;
}