#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        vector<int> result(nums.size());
        int runningXor = 0;
        for (int i = 0; i < nums.size(); ++i)
            runningXor = (runningXor ^ nums[i]);
        int numsSz = nums.size() - 1;
        for (int i = numsSz, j = 0; i >= 0; --i, ++j) {
            result[j] = ((1 << maximumBit) - 1) - runningXor;
            runningXor = (runningXor ^ nums[i]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 1, 3};
    vector<int> output = sol.getMaximumXor(nums, 2);
    vector<int> expected = {0, 3, 2, 3};
    assert(output.size() == expected.size());
    for (int i = 0; i < expected.size(); ++i)
        assert(output[i] == expected[i]);
    return 0;
}

