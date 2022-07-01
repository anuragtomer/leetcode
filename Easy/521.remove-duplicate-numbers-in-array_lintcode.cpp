#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
  int deduplication(vector<int> &nums) {
    unordered_set<int> set;
    int j = 0;
    for (int i = 0, n = nums.size(); i < n; ++i) {
      if (set.find(nums[i]) == set.end()) {
        set.insert(nums[i]);
        nums[j] = nums[i];
        ++j;
      }
    }
    return j;
  }
};
int main() {
  Solution sol;

  return 0;
}

