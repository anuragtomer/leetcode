#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestPerimeter(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 2; --i) {
      if (nums[i] < nums[i - 1] + nums[i - 2])
        return (nums[i] + nums[i - 1] + nums[i - 2]);
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 1, 2};
  assert(5 == sol.largestPerimeter(nums));
  nums = {1, 2, 1};
  assert(0 == sol.largestPerimeter(nums));
  return 0;
}
