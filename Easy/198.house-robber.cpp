/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
/* private:
    Recursive approach:
    
    int robRecur(vector<int> &nums, int index, vector<int> &sum) {
        if (index >= nums.size())
            return 0;
        if (sum[index] == -1)
            sum[index] = max((nums[index]+robRecur(nums, index+2, sum)), robRecur(nums, index+1, sum));
        return sum[index];
    }

public:
    int rob(vector<int>& nums) {
        vector<int> sum(nums.size(), -1);
        return robRecur(nums, 0, sum);
    } */
public:
    /* 
        Iterative but too much memory.
    int rob(vector<int> &nums) {
        int nusz = nums.size();
        vector<int> sum(nusz+1, -1);
        if (nusz == 0)
            return 0;
        if (nusz == 1)
            return nums[0];
        sum[0] = 0;
        sum[1] = nums[0];
        for (int i = 1, j = 2; i < nusz; i++, j++) {
            sum[j] = max(nums[i] + sum[j-2], sum[j-1]);
        }
        return sum[nusz];
    } */

    // Iterative but constant memory.
    int rob(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int first = 0;
        int second = 0;
        for (int num: nums) {
            int third = second;
            second = max(num + first, second);
            first = third;
        }
        return second;
    }
};
// @lc code=end

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    Solution sol;
    cout << sol.rob(nums);
    return 0;
}