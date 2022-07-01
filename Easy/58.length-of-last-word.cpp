/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int currSize = 0;
        int lastSize = 0;
        for (int i = 0; i < s.size(); ++i) {
            lastSize = (currSize != 0) ? currSize: lastSize;
            currSize = 0;
            while(s[i] != ' ' && i < s.size()) {
                ++currSize;
                ++i;
            }
        }
        return (currSize != 0) ? currSize : lastSize;
    }
};
// @lc code=end

int main() {
    string s;
    getline(cin, s);
    Solution sol;
    cout << sol.lengthOfLastWord(s);
    return 0;
}