#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /* DP solution
    bool PredictTheWinner(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                dp[j][j + i] = max(nums[j + i] - dp[j][j + i - 1], nums[j] - dp[j + 1][j + i]);
            }
        }
        return dp[0][n - 1] >= 0; // player1 get more score points than player2
    }
*/
    // Recursive solution
   private:
    bool helper(vector<int> &nums, int i, int j, int sumA, int sumB, bool turnA) {
        if (i > j)
            return sumA >= sumB;
        if (turnA) {
            return helper(nums, i + 1, j, sumA + nums[i], sumB, false) || // A wants to win via any path.
                   helper(nums, i, j - 1, sumA + nums[j], sumB, false);
        } else {
            return helper(nums, i + 1, j, sumA, sumB + nums[i],
                          true) && // this is the trick here. B wants to win via all paths.
                   helper(nums, i, j - 1, sumA, sumB + nums[j], true);
        }
    }

   public:
    bool PredictTheWinner(vector<int> &nums) { return helper(nums, 0, nums.size() - 1, 0, 0, true); }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 2};
    assert(!sol.PredictTheWinner(nums));
    nums = {1, 5, 233, 7};
    assert(sol.PredictTheWinner(nums));
    return 0;
}

