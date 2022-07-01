/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest
 * sum and return its sum.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int> &nums) {
        int sum = nums[0];
        int result = nums[0];
        for (auto i = 1; i < nums.size(); ++i) {
            sum = max(nums[i], sum + nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(nums);
    return 0;
}