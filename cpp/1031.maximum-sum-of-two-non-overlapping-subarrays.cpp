#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int helper(vector<int> &nums, int firstLen, int secondLen, int n) {
    vector<int> leftSum(n + 1), rightSum(n + 1);
    int sumL = 0, sumR = 0;
    for (int i = 0, j = n - 1; i < n; ++i, --j) {
      sumL += nums[i];
      sumR += nums[j];
      leftSum[i + 1] = max(leftSum[i], sumL);
      rightSum[j] = max(rightSum[j + 1], sumR);
      if (i + 1 >= firstLen)
        sumL -= nums[i + 1 - firstLen];
      if (i + 1 >= secondLen)
        sumR -= nums[j - 1 + secondLen];
    }
    int result = 0;
    for (int i = 0; i < n; ++i)
      result = max(result, leftSum[i] + rightSum[i]);
    return result;
  }

 public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    return max(helper(nums, firstLen, secondLen, nums.size()),
               helper(nums, secondLen, firstLen, nums.size()));
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int firstLen, secondLen;
  nums = {0, 6, 5, 2, 2, 5, 1, 9, 4}, firstLen = 1, secondLen = 2;
  assert(sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) == 20);
  nums = {3, 8, 1, 3, 2, 1, 8, 9, 0}, firstLen = 3, secondLen = 2;
  assert(sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) == 29);
  nums = {2, 1, 5, 6, 0, 9, 5, 0, 3, 8}, firstLen = 4, secondLen = 3;
  assert(sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) == 31);
  cout << "All test cases passed.";
  return 0;
}
