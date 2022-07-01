#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int helper(vector<int> &arr, int d, vector<int> &dp, int i) {
        if (i >= arr.size() || i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        dp[i] = 1;
        int n = arr.size();
        for (int j = i - 1; j >= max(i - d, 0) && arr[i] > arr[j]; --j) {
            dp[i] = max(dp[i], 1 + helper(arr, d, dp, j));
        }
        for (int j = i + 1; j <= min(n - 1, i + d) && arr[i] > arr[j]; ++j) {
            dp[i] = max(dp[i], 1 + helper(arr, d, dp, j));
        }
        return dp[i];
    }

   public:
    int maxJumps(vector<int> &arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        for (int i = 0; i < n; ++i)
            dp[i] = helper(arr, d, dp, i);
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;

    return 0;
}

