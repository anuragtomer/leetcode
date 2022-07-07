#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int minLen = INT_MAX, n = nums.size(), j = 0, i = 0;
        for (; i < n; ++i) {
            s -= nums[i];
            while (s <= 0 && j < n) {
                minLen = min(minLen, i - j + 1);
                s += nums[j];
                j++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    Solution sol;
    int s;
    vector<int> nums;
    s = 7, nums = {2, 3, 1, 2, 4, 3};
    assert(2 == sol.minSubArrayLen(s, nums));
    return 0;
}
