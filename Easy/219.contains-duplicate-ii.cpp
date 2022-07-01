/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = i;
            } else {
                if ((i - hash[nums[i]]) <= k)
                    return true;
                hash[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution sol;
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> k;
    cout << boolalpha << sol.containsNearbyDuplicate(nums, k);
    return 0;
}