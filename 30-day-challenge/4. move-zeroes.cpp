/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the
 * non-zero elements.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int> &nums) {
        int count = 0;
        int non_zero = 0;
        for (auto may_be_zero = 0; may_be_zero < nums.size(); may_be_zero++) {
            if (nums[may_be_zero] != 0) {
                nums[non_zero] = nums[may_be_zero];
                non_zero++;
            }
        }
        for (; non_zero < nums.size(); ++non_zero)
            nums[non_zero] = 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums{0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}