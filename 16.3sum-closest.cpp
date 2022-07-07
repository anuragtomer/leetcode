#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        int closestDistance = INT_MAX;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if ((abs(nums[i] + nums[j] + nums[k] - target)) < closestDistance) {
                        closestDistance = abs(nums[i] + nums[j] + nums[k] - target);
                        result = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return result;
    }
};

*/
class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int closestDistance = INT_MAX;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1, k = nums.size() - 1; k > j;) {
                if ((abs(nums[i] + nums[j] + nums[k] - target)) < closestDistance) {
                    closestDistance = abs(nums[i] + nums[j] + nums[k] - target);
                    result = nums[i] + nums[j] + nums[k];
                } else if (nums[i] + nums[j] + nums[k] < target) {
                    j++;
                } else
                    k--;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    assert(2 == sol.threeSumClosest(nums, 1));
    return 0;
}

