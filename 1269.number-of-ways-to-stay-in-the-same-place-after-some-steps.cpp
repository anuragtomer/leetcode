#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int _numWays(int steps, int arrLen, int currentLocation, vector<vector<int>> &dp) {
        int MOD = 1e9 + 7;
        if (steps == 0)
            return currentLocation == 0;
        if (currentLocation > steps)
            return 0;
        if (dp[currentLocation][steps] != -1)
            return dp[currentLocation][steps];
        int count = 0;
        if (currentLocation > 0)
            count = (count + _numWays(steps - 1, arrLen, currentLocation - 1, dp)) % MOD;
        if (currentLocation + 1 < arrLen)
            count = (count + _numWays(steps - 1, arrLen, currentLocation + 1, dp)) % MOD;
        count = (count + _numWays(steps - 1, arrLen, currentLocation, dp)) % MOD;
        dp[currentLocation][steps] = count;
        return count;
    }

   public:
    int numWays(int steps, int arrLen) {
        int count = 0;
        vector<vector<int>> dp(steps / 2 + 1, vector<int>(steps + 1, -1));
        return _numWays(steps, arrLen, 0, dp);
    }
};

int main() {
    Solution sol;

    return 0;
}

