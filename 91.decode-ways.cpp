#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
      int numDecodings(string s) {
            int n = s.size();
            vector<int> dp(n + 1);
            dp[n] = 1;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '0')
                    dp[i] = 0;
                else {
                    dp[i] = dp[i + 1];
                    if ((i < n - 1) && ((s[i] == '1') || (s[i] == '2' && s[i + 1] < '7')))
                        dp[i] += dp[i + 2];
                }
            }
            return s.empty() ? 0 : dp[0];
        }
        */
    // Another dp solution
    bool isValid(string s) {
        if (s.size() == 2)
            if (s[0] == '0')
                return false;
        int num = atoi(s.c_str());
        return num >= 1 && num <= 26;
    }
    int helper(string s, int i, vector<int> &counts) {
        if (i >= s.size())
            return 1;
        if (counts[i] != -1)
            return counts[i];
        int count = 0;
        if (isValid(s.substr(i, 1)))
            count += helper(s, i + 1, counts);
        if (i + 1 < s.size() && isValid(s.substr(i, 2)))
            count += helper(s, i + 2, counts);
        counts[i] = count;
        return count;
    }

    int numDecodings(string s) {
        vector<int> counts(s.size(), -1);
        counts[0] = helper(s, 0, counts);
        return counts[0];
    }
};
int main() {
    Solution sol;
    assert(2 == sol.numDecodings("12"));
    assert(3 == sol.numDecodings("226"));
    assert(1 == sol.numDecodings("10"));
    return 0;
}
