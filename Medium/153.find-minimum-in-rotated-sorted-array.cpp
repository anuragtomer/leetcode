#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid] && nums[mid] < nums[right]) {
                return nums[left];
            } else if (nums[left] <= nums[mid] && nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[left] > nums[mid] && nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    Solution sol;

    return 0;
}

