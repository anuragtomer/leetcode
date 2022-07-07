#include <iostream>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
   public:
    void sortColors(vector<int> &nums) {
        int zero = 0, two = nums.size() - 1;
        for (int i = 0; i <= two; ++i) {
            if (nums[i] == 2) {
                if (i != two) {
                    swap(nums[i], nums[two]);
                    i--;
                }
                two--;
            } else if (nums[i] == 0) {
                if (i != zero) {
                    swap(nums[i], nums[zero]);
                    i--;
                }
                zero++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> expected = {0, 0, 1, 1, 2, 2};
    sol.sortColors(nums);
    testResp(nums, expected);
    return 0;
}
