#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
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
};
int main() {
    Solution sol;
    assert(2 == sol.numDecodings("12"));
    assert(3 == sol.numDecodings("226"));
    assert(1 == sol.numDecodings("10"));
    return 0;
}
