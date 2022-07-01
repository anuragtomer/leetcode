#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canJump(vector<int> &nums) {
        vector<bool> reach(nums.size(), false);
        reach[0] = true;
        for (auto i = 0; i < nums.size(); i++) {
            if (reach[i] == true) {
                if (i + nums[i] < nums.size() && reach[i + nums[i]] == true)
                    continue;
                for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
                    reach[i + j] = true;
                }
            }
        }
        return reach[nums.size() - 1] == true;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums = {2, 3, 1, 1, 4};
    assert(true == sol.canJump(nums));
    nums = {3, 2, 1, 0, 4};
    assert(false == sol.canJump(nums));
    nums = {2, 0};
    assert(true == sol.canJump(nums));
    return 0;
}
