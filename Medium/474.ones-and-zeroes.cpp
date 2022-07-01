#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

   public:
    /* Slower code */
    /*
 int findMaxForm(vector<string> &strs, int m, int n) {
     vector<pair<int, int>> counts;
     for (auto str : strs) {
         int zeros = 0, ones = 0;
         for (auto ch : str) {
             if (ch == '0')
                 zeros++;
             if (ch == '1')
                 ones++;
         }
         counts.push_back({zeros, ones});
     }
     int l = counts.size();
     vector<vector<vector<int>>> dp =
         vector<vector<vector<int>>>(l + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
     for (int i = 1; i <= l; ++i) {
         for (int j = 0; j <= m; ++j) {
             for (int k = 0; k <= n; ++k) {
                 dp[i][j][k] = dp[i - 1][j][k];
                 if (j >= counts[i - 1].first && k >= counts[i].second)
                     dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - counts[i].first][k - counts[i].second]);
             }
         }
     }
     return dp[l][m][n];
 }
 */
    // A bit faster code.
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0));
        for (auto &s : strs) {
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size() - ones;
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"10", "0", "1"};
    int m = 1, n = 1;
    if (2 != sol.findMaxForm(strs, m, n)) {
        cout << sol.findMaxForm(strs, m, n) << endl;
    }
    strs = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3;
    if (4 != sol.findMaxForm(strs, m, n)) {
        cout << sol.findMaxForm(strs, m, n) << endl;
    }
    return 0;
}

