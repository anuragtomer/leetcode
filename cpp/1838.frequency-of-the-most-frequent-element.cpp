#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /*
  int maxFrequency(vector<int> &nums, long k) {
     int i = 0, j;
     sort(nums.begin(), nums.end());
     for (j = 0; j < nums.size(); ++j) {
         k += nums[j];
         if (k < (long)nums[j] * (j - i + 1))
             k -= nums[i++];
     }
     return j - i;
  }*/
  int maxFrequency(vector<int> &nums, int k) {
    int longest = 1, left = 0, right;
    long curr_sum = 0;
    sort(nums.begin(), nums.end());
    for (right = 0; right < nums.size(); ++right) {
      curr_sum += nums[right];
      while (left <= right &&
             (long)nums[right] * (right - left + 1) - curr_sum > k) {
        // nums[right] * (right - left + 1) - (nums[left] + nums[left + 1] + .. + nums[right]) > k
        // i.e. cost to make them all same > k, then time to reduce the window.
        curr_sum -= nums[left];
        ++left;
      }
      longest = max(longest, right - left + 1);
    }
    return longest;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 4, 8, 13};
  assert(2 == sol.maxFrequency(nums, 5));
  nums = {1, 2, 4};
  assert(3 == sol.maxFrequency(nums, 5));
  nums = {3, 6, 9};
  assert(1 == sol.maxFrequency(nums, 2));
  return 0;
}
