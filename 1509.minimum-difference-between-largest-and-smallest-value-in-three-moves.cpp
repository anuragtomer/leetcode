#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDifference(vector<int> &nums) {
        int n = nums.size();
        if (n < 5)
            return 0;
        sort(nums.begin(), nums.end());
        return min({nums[n - 4] - nums[0], nums[n - 3] - nums[1], nums[n - 2] - nums[2], nums[n - 1] - nums[3]});
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 3, 2, 4};
    assert(0 == sol.minDifference(nums));
    nums = {1, 5, 0, 10, 14};
    assert(1 == sol.minDifference(nums));
    return 0;
}

