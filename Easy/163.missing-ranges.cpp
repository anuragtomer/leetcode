#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        if (nums.empty()) {
            vector<string> result;
            if (lower == upper)
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower) + "->" + to_string(upper));
            return result;
        }
        vector<string> result;
        if (nums.front() != lower) {
            if (lower + 1 == nums.front())
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower) + "->" + to_string(nums.front() - 1));
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i - 1] + 1) {
                if (nums[i] - 1 == nums[i - 1] + 1)
                    result.push_back(to_string(nums[i] - 1));
                else
                    result.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            }
        }
        if (nums.back() != upper) {
            if (upper - 1 == nums.back())
                result.push_back(to_string(upper));
            else
                result.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        }
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

