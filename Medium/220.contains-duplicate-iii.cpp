/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */
#include<iostream>
#include<vector>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if ( k == 0 || t < 0 || nums.size() < 2)
            return false;
        set<long>record;
        int nLen = nums.size();
        for (int i = 0; i < nLen; ++i) {
            if (i > k) // If no of we have crossed the boundary of allowed index, start deleting elements in set from begining.
                record.erase(nums[i - k - 1]); // Delete the first element in record
            set<long>::iterator justGreater = record.lower_bound((long)nums[i] - t);
            if (justGreater != record.end() && abs(nums[i] - *justGreater) <= t)
                return true;
            record.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution sol;
    int n, k, t;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cin >> k;
    cin >> t;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate(nums, k, t);
    return 0;
}
