#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int majorityElement(vector<int> &nums) {
        int majority, count;
        if (nums.size() == 1)
            return nums[0];
        majority = nums[0];
        count = 1;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] == majority)
                count++;
            else {
                count--;
                if (count == 0) {
                    majority = nums[i];
                    count = 1;
                }
            }
        }
        return majority;
    }
};

int main() {
    Solution sol;
    vector<int> nums{3, 2, 3};
    assert(3 == sol.majorityElement(nums));
    nums = {2, 2, 1, 1, 1, 2, 2};
    assert(2 == sol.majorityElement(nums));
    return 0;
}
