#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int triangleNumber(vector<int> &nums) {
        int count = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += (right - left);
                    right--;
                } else
                    left++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 4};
    assert(sol.triangleNumber(nums) == 3);
    nums = {4, 2, 3, 4};
    assert(sol.triangleNumber(nums) == 4);
    return 0;
}

