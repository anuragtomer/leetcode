#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int threeSumSmaller(vector<int> &nums, int target) {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    count += right - left;
                    ++left;
                } else
                    --right;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    return 0;
}

