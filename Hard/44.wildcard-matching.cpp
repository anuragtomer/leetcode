#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); ++i) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main() {
    Solution sol;
    assert(!sol.isMatch("aa", "a"));
    assert(sol.isMatch("aa", "*"));
    assert(!sol.isMatch("cb", "?a"));
    assert(sol.isMatch("adceb", "*a*b"));
    assert(!sol.isMatch("acdcb", "a*c?b"));
    assert(sol.isMatch("", "*******"));
    assert(sol.isMatch("", ""));
    assert(!sol.isMatch(
        "aaabaaabbababaabbabaababbbbbbaabababbbaabaaaabbbbabbbbaaaaabaabbbbaaaabbabbaaabbabbbababbaaaabbabbabbbbabaabba"
        "bbbabbbbabbbbbaabbbababaaaababbbbababababababbabbbbaaaaababbaaababbabaababbbaaabbbbbababab",
        "aa*abab*a*a**a*b****ba*ba*aa*****b****b**bbbba*b*b*a**b**b*aab***b*bb***baa*b***a***baa*****a*a*a*ab**a"));
    return 0;
}

