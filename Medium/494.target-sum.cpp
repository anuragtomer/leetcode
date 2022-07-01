#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
/*
class Solution {
    int getLoc(int i, int j) { return i * 2000 + j; }
    int helper(vector<int> &nums, int index, int target, unordered_map<int, int> &dp) {
        if (index == nums.size())
            return (target == 0) ? 1 : 0;
        if (dp.find(getLoc(index, target)) != dp.end())
            return dp[getLoc(index, target)];
        int positive = helper(nums, index + 1, target + nums[index], dp);
        int negative = helper(nums, index + 1, target - nums[index], dp);
        dp[getLoc(index, target)] = positive + negative;
        return dp[getLoc(index, target)];
    }

   public:
    int findTargetSumWays(vector<int> &nums, int target) {
        unordered_map<int, int> dp;
        return helper(nums, 0, target, dp);
    }
};
*/
class Solution {
   public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (target + sum) % 2 == 1 ? 0 : subsetSum(nums, (target + sum) / 2);
    }

    int subsetSum(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int n : nums)
            for (int i = target; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[target];
    }
};
int main() {
    Solution sol;

    return 0;
}

