/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (auto n : nums)
            res ^= n;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums{2, 3, 4, 5, 4, 3, 2};
    cout << sol.singleNumber(nums);
    return 0;
}