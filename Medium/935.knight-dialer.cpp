#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int helper(vector<vector<int>> &dp, vector<vector<int>> &edges, int steps, int currentNode) {
        if (steps == 0)
            return 1;
        if (dp[currentNode][steps] != -1)
            return dp[currentNode][steps];
        int MOD = 1e9 + 7;
        dp[currentNode][steps] = 0;
        for (auto neigh : edges[currentNode]) {
            dp[currentNode][steps] = (dp[currentNode][steps] + helper(dp, edges, steps - 1, neigh)) % MOD;
        }
        return dp[currentNode][steps];
    }

   public:
    int knightDialer(int n) {
        vector<vector<int>> dp(10, vector<int>(n, -1));
        int MOD = 1e9 + 7;
        vector<vector<int>> edges = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        int count = 0;
        for (int i = 0; i < 10; ++i)
            count = (count + helper(dp, edges, n - 1, i)) % MOD;
        return count;
    }
};

int main() {
    Solution sol;

    return 0;
}

