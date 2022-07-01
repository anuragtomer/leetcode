/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElementRecursive(vector<int> nums, int lb, int ub) {
        if (lb == ub)
            return lb-1;
        int mid = lb + (ub - lb)/2;
        if ((mid-1) >= 0 && nums[mid] > nums[mid-1] && (mid+1) < nums.size() && nums[mid] > nums[mid+1])
            return mid-1;
        if (mid-1 >=0 && nums[mid-1] > nums[mid])
            return findPeakElementRecursive(nums, lb, mid-1);
        else if (mid+1 < nums.size())
            return findPeakElementRecursive(nums, mid+1, ub);
        else
            return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return 0;
        vector<int> newNums(nums.size() + 2, INT_MIN);
        for (unsigned int i = 1; i < newNums.size()-1; i++)
            newNums[i] = nums[i-1];
        return findPeakElementRecursive(newNums, 0, newNums.size()-1);
    }
};
// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << sol.findPeakElement(nums);
    return 0;
}