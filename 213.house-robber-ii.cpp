#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int robber(vector<int> nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; ++i) {
            // either I stay with last Loot, or I add currentHouseCash to loot before that.
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[n];
    }

   public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums.front();
        return max(robber(vector<int>(nums.begin(), nums.end() - 1)),
                   robber(vector<int>(nums.begin() + 1, nums.end())));
    }
};
class Solution {
  int robber(vector<int> nums) {
    int n = nums.size();
    int IRobbed = nums[0], IDidNotRob = 0;
    for (int i = 1; i < n; ++i) {
      int lastRobbery = IRobbed;
      IRobbed = max(IRobbed, IDidNotRob + nums[i]);
      IDidNotRob = lastRobbery;
    }
    return max(IRobbed, IDidNotRob);
  }
public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 0)
      return 0;
    if (size == 1)
      return nums[0];
    return max(robber(vector<int>(nums.begin(), nums.begin() + size - 1)), 
               robber(vector<int>(nums.begin() + 1, nums.end())));
  }
};

int main() {
    Solution sol;

    return 0;
}

