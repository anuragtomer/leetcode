#include <iostream>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> previous_index(n, -1);
        int max_idx = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    previous_index[i] = j;
                }
            }
            if (dp[i] > dp[max_idx])
                max_idx = i;
        }
        vector<int> result;
        int i = max_idx;
        while (i >= 0) {
            result.push_back(nums[i]);
            i = previous_index[i];
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<int> output = {2, 1};
    vector<int> response = sol.largestDivisibleSubset(nums);
    testResp(response, output);
    nums = {1, 2, 4, 8};
    output = {8, 4, 2, 1};
    response = sol.largestDivisibleSubset(nums);
    testResp(response, output);
    return 0;
}
