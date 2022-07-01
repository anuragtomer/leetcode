/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = INT_MIN;
        int count = 0;
        for (int num: nums) {
            if (num == major)
                count++;
            else
                count--;
            if (count == -1) {
                count = 1;
                major = num;
            }
        }
        return major;
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
    cout << sol.majorityElement(nums);
    return 0;
}