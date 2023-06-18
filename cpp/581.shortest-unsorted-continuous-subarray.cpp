#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size(), start = -1, end = n, curr_min = INT_MAX,
        curr_max = INT_MIN;
    for (int j = n - 1, i = 0; j >= 0 && i < n; --j, ++i) {
      if (curr_min > nums[j])
        curr_min = nums[j];
      else if (nums[j] > curr_min)
        start = j;

      if (curr_max < nums[i])
        curr_max = nums[i];
      else if (nums[i] < curr_max)
        end = i;
    }
    if (start == -1)
      return 0;
    return end - start + 1;
  }
};
int main() {
  Solution sol;
  vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  assert(sol.findUnsortedSubarray(nums) == 5);

  nums = {1, 2, 3, 4};
  assert(sol.findUnsortedSubarray(nums) == 0);

  nums = {1};
  assert(sol.findUnsortedSubarray(nums) == 0);

  nums = {1, 2, 3, 3, 3};
  assert(sol.findUnsortedSubarray(nums) == 0);
  return 0;
}

