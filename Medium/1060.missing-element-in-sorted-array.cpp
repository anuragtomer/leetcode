#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingElement(vector<int> &nums, int k) {
    int totalMiss = nums.back() - nums.front() + 1 - nums.size();

    if (totalMiss < k)
      return nums.back() + k - totalMiss;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = left + right / 2;
      int missingCountinLeftHalf = (nums[mid] - nums[left]) - (mid - left);
      if (missingCountinLeftHalf < k) {
        left = mid;
        k -= missingCountinLeftHalf;
      } else {
        right = mid;
      }
    }
    return nums[left] + k;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4, 7, 9, 10};
  assert(5 == sol.missingElement(nums, 1));
  nums = {4, 7, 9, 10};
  assert(8 == sol.missingElement(nums, 3));
  nums = {1, 2, 4};
  assert(6 == sol.missingElement(nums, 3));

  return 0;
}

