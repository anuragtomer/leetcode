#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> result = vector<int>(n);
        result[0] = 0;
        for (int i = 1; i < n; ++i) {
            result[i] = INT_MAX;
            for (int j = 0; j < i; ++j) {
                if (i <= j + nums[j])
                    result[i] = min(result[i], result[j] + 1);
            }
        }
        return result[n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    assert(2 == sol.jump(nums));
    nums = {2, 3, 0, 1, 4};
    assert(2 == sol.jump(nums));
    return 0;
}

