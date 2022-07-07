#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int lb = 0, ub = nums.size() - 1;
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (nums[mid] > nums[ub])
        lb = mid + 1;
      else
        ub = mid;
    }
    return nums[lb];
  }
};

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

