#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
   public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int &num = nums[i];
            for (int i = target; i >= num; --i)
                dp[i] = dp[i] || dp[i - num];
        }
        return dp[target];
    }
};
/* Another Solution */
/*
class Solution {
  int helper(vector<int> &nums, int i, int target,vector<vector<int>> &dp) {
    if (i == nums.size())
      return target == 0;
    if (target < 0) return 0;
    if (target == 0) return 1;
    if (dp[i][target] != -1) return dp[i][target];
    dp[i][target] = 0;
    if (helper(nums, i + 1, target - nums[i], dp) > 0){
      dp[i][target] = 1;
      return 1;
    }
    dp[i][target] = helper(nums, i + 1, target, dp);
    return dp[i][target];
  }
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int target = sum/2;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    return helper(nums, 0, target, dp) >= 1;
  }
};
*/
int main() {
    Solution sol;

    return 0;
}

