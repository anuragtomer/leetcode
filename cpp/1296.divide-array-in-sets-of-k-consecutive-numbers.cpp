#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPossibleDivide(vector<int> &nums, int k) {
    multiset<int> set(nums.begin(), nums.end());
    sort(nums.begin(), nums.end());
    for (auto num : nums) {
      if (set.find(num) != set.end()) {
        int count = 0;
        while (count < k) {
          if (set.find(num + count) == set.end())
            return false;
          else
            set.erase(set.find(num + count));
          ++count;
        }
      }
    }
    return set.empty();
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 7, 8};
  assert(sol.isPossibleDivide(nums, 4));
  nums = {1, 2, 3, 3, 4, 4, 5, 6};
  assert(sol.isPossibleDivide(nums, 4));
  nums = {3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11};
  assert(sol.isPossibleDivide(nums, 3));
  nums = {1, 2, 3, 4};
  assert(not sol.isPossibleDivide(nums, 3));
  return 0;
}
