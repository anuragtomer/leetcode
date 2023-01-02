#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumSmaller(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int result = 0, i = 0;
    while (i < n) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        if (nums[i] + nums[j] + nums[k] < target) {
          result += (k - j);
          ++j;
        } else {
          --k;
        }
      }
      ++i;
    }
    return result;
  }
};

int main() {
  Solution sol;
  assert(sol.threeSumSmaller({-2, 0, 1, 3}, 2) == 2);
  assert(sol.threeSumSmaller({-2, 0, -1, 3}, 2) == 3);
  return 0;
}
