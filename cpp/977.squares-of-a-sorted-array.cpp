#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1, i = n - 1;
    while (left <= right) {
      if (abs(nums[left]) < abs(nums[right])) {
        result[i] = nums[right] * nums[right];
        --right;
      } else {
        result[i] = nums[left] * nums[left];
        ++left;
      }
      --i;
    }
    return result;
  }
};

int main() {
  Solution sol;
  auto lmatch = [](const vector<int> &exp, vector<int> out) {
    if (exp.size() != out.size())
      return false;
    for (int i = 0; i < exp.size(); ++i)
      if (exp[i] != out[i])
        return false;
    return true;
  };
  vector<int> nums, exp;
  nums = {-4, -1, 0, 3, 10};
  exp = {0, 1, 9, 16, 100};
  assert(lmatch(exp, sol.sortedSquares(nums)));
  nums = {-7, -3, 2, 3, 11};
  exp = {4, 9, 9, 49, 121};
  assert(lmatch(exp, sol.sortedSquares(nums)));
  return 0;
}
