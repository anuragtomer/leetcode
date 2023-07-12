#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &nums) {
    int dip = -1, n = nums.size();
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        dip = i;
        break;
      }
    }
    if (dip == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int just_greater = dip + 1;
    for (int i = dip + 2; i < n; ++i) {
      if (nums[i] > nums[dip] && nums[i] <= nums[just_greater]) {
        just_greater = i;
      }
    }
    swap(nums[dip], nums[just_greater]);
    reverse(nums.begin() + dip + 1, nums.end());
    return;
  }
};

int main() {
  auto lMatch = [](vector<int> out, vector<int> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i] != exp[i])
        return false;
    }
    return true;
  };

  Solution sol;
  vector<int> nums, expected, output;
  nums = {1, 2, 3};
  expected = {1, 3, 2};
  sol.nextPermutation(nums);
  assert(lMatch(nums, expected));
  nums = {3, 2, 1};
  expected = {1, 2, 3};
  sol.nextPermutation(nums);
  assert(lMatch(nums, expected));
  nums = {1, 1, 5};
  expected = {1, 5, 1};
  sol.nextPermutation(nums);
  assert(lMatch(nums, expected));
  return 0;
}
