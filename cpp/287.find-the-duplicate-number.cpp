#include <iostream>
#include <vector>

using namespace std;
/*
 * Constraints: 
 *  - O(n) Time.
 *  - O(1) Space.
 *  - Cannot modify the input array.
 */
class Solution {
   public:
    int findDuplicate(const vector<int> &nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    assert(2 == sol.findDuplicate(nums));
    nums = {2, 6, 4, 1, 3, 1, 5};
    assert(1 == sol.findDuplicate(nums));
    nums = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    assert(9 == sol.findDuplicate(nums));
    return 0;
}
