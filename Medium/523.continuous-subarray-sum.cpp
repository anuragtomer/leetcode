#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_set<int> modValues;
        int preSum = 0, currSum = 0;
        for (auto num : nums) {
            currSum = (currSum + num) % k;
            if (modValues.count(currSum))
                return true;
            modValues.insert(preSum);
            preSum = currSum;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {23, 2, 4, 6, 7};
    assert(sol.checkSubarraySum(nums, 6));
    nums = {23, 2, 6, 4, 7};
    assert(sol.checkSubarraySum(nums, 6));
    nums = {23, 2, 6, 4, 7};
    assert(!sol.checkSubarraySum(nums, 13));
    return 0;
}

