#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int dfs(vector<int> &preSum, int m, int p, vector<vector<int>> &dp) {
        if (p + 2 * m >= preSum.size()) // take all remaining
            return preSum[p];
        if (dp[p][m] > 0)
            return dp[p][m];
        int res = 0;
        for (int i = 1; i <= 2 * m; ++i) {
            res = max(res, preSum[p] - dfs(preSum, max(i, m), p + i, dp));
        }
        dp[p][m] = res;
        return res;
    }

   public:
    int stoneGameII(vector<int> &piles) {
        vector<int> preSum(piles.begin(), piles.end());
        int n = piles.size();
        for (int i = n - 2; i >= 0; --i)
            preSum[i] += preSum[i + 1];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return dfs(preSum, 1, 0, dp);
    }
};
int main() {
    Solution sol;
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << sol.stoneGameII(piles);
    return 0;
}

