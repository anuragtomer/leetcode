#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1)
            return 0;
        int prod = 1, left = 0, count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            prod *= nums[right];
            while (prod >= k)
                prod /= nums[left++];
            count += right - left + 1;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    assert(8 == sol.numSubarrayProductLessThanK(nums, 100));
    return 0;
}

