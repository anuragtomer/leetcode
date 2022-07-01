#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1, k = n - 1; j < k;) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
            while (i < n - 2 && nums[i] == nums[i + 1])
                ++i;
        }
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

