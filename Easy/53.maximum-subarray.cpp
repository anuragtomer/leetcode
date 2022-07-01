/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
/* #include <vector>
#include <iostream>
using namespace std;
 */
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], i, currMax = nums[0];
        for (i = 1; i < nums.size(); ++i) {
            currMax = max(nums[i], currMax+nums[i]);
            ans = max(ans, currMax);
        }
        return ans;
    }
};
// @lc code=end
/* 
int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) 
        cin >> nums[i];
    cout << sol.maxSubArray(nums);
    return 0;
} */
