#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i || nums[i] < 0 || nums[i] >= nums.size())
                continue;
            if (nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
                --i;
            }
        }
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != i)
                return i;
        return nums.size();
    }
};

int main() {
    Solution sol;

    return 0;
}

