#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param nums: an array of integer
    * @param k: an integer
    * @return: the largest sum
    */
  int maxSubarray4(vector<int> &nums, int k) {
    if (nums.size() < k)
      return 0;
    int n = nums.size();
    int currentSum = nums[0], i = 1;
    vector<int> maxSum(n);
    maxSum[0] = nums[0];
    while (i < n) {
      currentSum = max(currentSum + nums[i], nums[i]);
      maxSum[i] = currentSum;
      ++i;
    }
    int sum = 0;
    i = 0;
    while (i < k) {
      sum += nums[i];
      ++i;
    }
    int result = sum;
    while (i < n) {
      sum = sum + nums[i] - nums[i - k];
      result = max(result, sum);
      result = max(result, sum + maxSum[i - k]);
      ++i;
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

