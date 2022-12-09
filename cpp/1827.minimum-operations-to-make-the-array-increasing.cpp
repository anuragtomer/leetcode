#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minOperations(vector<int> &nums) {
        int count = 0;
        int last = nums[0];
        int newNum;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= last) {
                newNum = last + 1;
                count += (newNum - nums[i]);
                nums[i] = newNum;
            }
            last = nums[i];
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    assert(sol.minOperations(nums) == 3);
    return 0;
}

