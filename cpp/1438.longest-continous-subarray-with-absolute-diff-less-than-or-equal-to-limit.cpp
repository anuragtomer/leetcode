#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int> &nums, int limit) {
    int maxLen = 0;
    set<pair<int, int>> ordered_set;
    for (int left = 0, right = 0; right < nums.size(); ++right) {
      ordered_set.insert({nums[right], right});
      while (ordered_set.rbegin()->first - ordered_set.begin()->first > limit) {
        ordered_set.erase({nums[left], left});
        ++left;
      }
      maxLen = max(static_cast<int>(ordered_set.size()), maxLen);
    }
    return maxLen;
  }
};
int main() {
  Solution sol;
  vector<int> nums = {8, 2, 4, 7};
  int limit = 4;
  assert(2 == sol.longestSubarray(nums, limit));
  nums = {10, 1, 2, 4, 7, 2};
  limit = 5;
  assert(4 == sol.longestSubarray(nums, limit));
  return 0;
}
