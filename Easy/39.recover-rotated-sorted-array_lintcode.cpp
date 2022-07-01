#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param nums: An integer array
    * @return: nothing
    */
  void recoverRotatedSortedArray(vector<int> &nums) {
    vector<int> sortedArray(nums.size());
    int lb = 0, ub = nums.size() - 1;
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (nums[mid] > nums[ub])
        lb = mid + 1;
      else if (nums[mid] < nums[ub])
        ub = mid;
      else
        ub = ub - 1;
    }
    reverse(nums.begin(), nums.begin() + lb);
    reverse(nums.begin() + lb, nums.end());
    reverse(nums.begin(), nums.end());
  }
};
int main() {
  Solution sol;

  return 0;
}

