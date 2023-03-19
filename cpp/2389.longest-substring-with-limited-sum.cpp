#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    sort(nums.begin(), nums.end());
    vector<int> sums(nums.size());
    sums[0] = nums[0];
    for (int i = 1; i < sums.size(); ++i)
      sums[i] = sums[i - 1] + nums[i];
    vector<int> ret;
    for (int i : queries)
      ret.push_back(upper_bound(sums.begin(), sums.end(), i) - sums.begin());
    return ret;
  }
};

int main() {
  Solution sol;
  auto lmatch = [](vector<int> &a, vector<int> &b) {
    if (a.size() != b.size())
      return false;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  };
  vector<int> nums = {4, 5, 2, 1}, queries = {3, 10, 21};
  vector<int> result = sol.answerQueries(nums, queries);
  vector<int> output = {2, 3, 4};
  assert(lmatch(result, output));
  nums = {2, 3, 4, 5}, queries = {1}, output = {0};
  result = sol.answerQueries(nums, queries);
  assert(lmatch(result, output));
  return 0;
}
