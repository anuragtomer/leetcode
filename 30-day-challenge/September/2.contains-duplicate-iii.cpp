#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.size() < 2 || t < 0 || k == 0)
            return false;

        set<int> sorted_nums;
        int i = 0;
        for (auto num : nums) {
            if ((int)sorted_nums.size() > k) {
                sorted_nums.erase(nums[i - k - 1]); // erase the beginning element.
            }
            auto closest_number = sorted_nums.lower_bound(nums[i]);
            if (closest_number != sorted_nums.end() && abs(*closest_number - nums[i]) <= t)
                return true;
            sorted_nums.insert(num);
            ++i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3, t = 0;
    assert(sol.containsNearbyAlmostDuplicate(nums, k, t));
    nums = {1, 0, 1, 1};
    k = 1, t = 2;
    assert(sol.containsNearbyAlmostDuplicate(nums, k, t));
    nums = {1, 5, 9, 1, 5, 9};
    k = 2, t = 3;
    assert(sol.containsNearbyAlmostDuplicate(nums, k, t) == false);
    return 0;
}
