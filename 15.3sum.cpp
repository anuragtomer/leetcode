#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0, n = nums.size(); i < n - 2;) {
      for (int j = i + 1, k = n - 1; j < k;) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          result.push_back({nums[i], nums[j], nums[k]});
          ++j;
          --k;
          while (j < k && nums[j] == nums[j - 1])
            ++j;
          while (j < k && nums[k] == nums[k + 1])
            --k;
        } else if (sum < 0) {
          ++j;
        } else {
          --k;
        }
      }
      ++i;
      while (i < n - 2 && nums[i] == nums[i - 1])
        ++i;
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}
