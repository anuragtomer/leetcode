/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        return nums.size() != hash.size();
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
    cout << boolalpha << sol.containsDuplicate(nums);
    return 0;
}