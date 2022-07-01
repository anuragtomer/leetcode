#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
    string text1;
    string text2;
    map<pair<int, int>, int> answer;

   public:
    /* int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // dp[i][j] is LCS of first i chars of text1 and j chars of text2.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j])
                    dp[i+1][j+1] = 1 + dp[i][j];
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[m][n];
    } */
    /*
    Exponential solution:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty())
            return 0;
        if (text1.back() == text2.back()) {
            text1.pop_back();
            text2.pop_back();
            return 1 + longestCommonSubsequence(text1, text2);
        }
        return max(longestCommonSubsequence(string(text1.begin(), text1.end() - 1), text2),
                   longestCommonSubsequence(text1, string(text2.begin(), text2.end() - 1)));
    }*/

    int my_lcs(int len1, int len2) {
        if (len1 == 0 || len2 == 0)
            return 0;
        pair<int, int> my_state{len1, len2};
        auto it = answer.find(my_state);
        if (it != answer.end())
            return it->second;
        if (text1[len1 - 1] == text2[len2 - 1])
            return answer[my_state] = 1 + my_lcs(len1 - 1, len2 - 1);
        return answer[my_state] = max(my_lcs(len1 - 1, len2), my_lcs(len1, len2 - 1));
    }
    int longestCommonSubsequence(string _text1, string _text2) {
        map<pair<int, int>, int>().swap(answer);
        text1 = _text1;
        text2 = _text2;
        return my_lcs(text1.length(), text2.length());
    }
};

int main() {
    Solution sol;
    assert(3 == sol.longestCommonSubsequence("abced", "ace"));
    assert(3 == sol.longestCommonSubsequence("abc", "abc"));
    assert(0 == sol.longestCommonSubsequence("abc", "def"));
    return 0;
}
