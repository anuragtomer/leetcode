/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0)
            return true;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        unordered_set<string> set;
        for (int i = 0; i < wordDict.size(); i++)
            set.insert(wordDict[i]);

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] == true) {
                    string str = s.substr(j, i-j);
                    if (set.find(str) != set.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
/* Timeout for large input
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0)
            return true;
        bool completeMatch = false;
        for (unsigned int i = 0; i < wordDict.size(); i++) {
            if (s.find(wordDict[i]) == 0) {
                completeMatch |= wordBreak(s.substr(wordDict[i].size()), wordDict);
                if (completeMatch == true)
                    return completeMatch;
            }
        }
        return completeMatch;
    }
*/
};
// @lc code=end

int main() {
    Solution sol;
    string s;
    int n;
    cout << "n:";
    cin >> n;
    cout << "string:";
    cin >> s;
    vector<string> wordDict(n);
    cout << "dictionary:";
    for (int i = 0; i < n; i++)
        cin >> wordDict[i];
    cout << "\n";
    cout << boolalpha << sol.wordBreak(s, wordDict);
    return 0;
}