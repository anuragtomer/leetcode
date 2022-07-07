/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int> &iNums) {
        int nums[iNums.size() + 2];
        int n = 1;
        for (int x : iNums) if (x > 0) nums[n++] = x;
        nums[0] = nums[n++] = 1;


        int dp[n][n] = {};
        for (int k = 2; k < n; ++k) {
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i)
                    dp[left][right] = max(dp[left][right],
                        nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

// [7,9,8,0,7,1,3,5]