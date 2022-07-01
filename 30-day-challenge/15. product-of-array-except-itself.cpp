/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // Brute Force method. Times out.
    /* vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> output;
        output.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                product *= nums[j];
            }
            output[i] = product;
        }
        return output;
    } */
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> left;
        left.resize(nums.size());
        left[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            left[i] = nums[i - 1] * left[i - 1];
        }
        vector<int> right;
        right.resize(nums.size());
        right[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] = nums[i + 1] * right[i + 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = left[i] * right[i];
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> input{1, 2, 3, 4};
    vector<int> output{24, 12, 8, 6};
    input = sol.productExceptSelf(input);
    for (auto num = 0; num < input.size(); num++) {
        assert(input[num] == output[num]);
    }
    input = {1, 2, 3, 0};
    output = {0, 0, 0, 6};
    input = sol.productExceptSelf(input);
    for (auto num = 0; num < input.size(); num++) {
        assert(input[num] == output[num]);
    }
    return 0;
}