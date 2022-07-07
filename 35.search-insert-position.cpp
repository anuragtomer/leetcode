#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] >= target)
                return i;
        return n;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int t = 5;
    assert(2 == sol.searchInsert(nums, t));
    t = 2;
    assert(1 == sol.searchInsert(nums, t));
    t = 7;
    assert(4 == sol.searchInsert(nums, t));
    t = 0;
    assert(0 == sol.searchInsert(nums, t));
    return 0;
}
