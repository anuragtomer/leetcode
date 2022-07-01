#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = nums.size(), i, c = 0; // c saves the current beginning of the longest array.
        // create a set of <value at i, i> that makes the longest array, keep them sorted by values.
        set<pair<int, int>> s;
        int ans = 0;
        for (i = 0; i < n; i++) { // Loop over all the nums.
            s.insert({nums[i], i});
            while ((s.size() > 1) && (abs(s.rbegin()->first - s.begin()->first) > limit)) {
                // while the difference of first and last entries in set is greater than limit, keep
                // removing from beginning of input array.
                s.erase({nums[c], c});
                c++;
            }
            ans = max(ans, (int)s.size());
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    assert(2 == sol.longestSubarray(nums, limit));
    nums = {10, 1, 2, 4, 7, 2};
    limit = 5;
    assert(4 == sol.longestSubarray(nums, limit));
    nums = {4, 2, 2, 2, 4, 4, 2, 2};
    limit = 0;
    assert(3 == sol.longestSubarray(nums, limit));
    return 0;
}
