#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool possible(vector<int> &nums, int count, int H) {
    int h = 0, n = nums.size(), i = 0;
    while (i < n) {
      h = h + (nums[i] / count) + ((nums[i] % count == 0) ? 0 : 1);
      if (h > H)
        return false;
      ++i;
    }
    return h <= H;
  }

 public:
  /**
    * @param piles: an array
    * @param H: an integer
    * @return: the minimum integer K
    */
  int minEatingSpeed(vector<int> &piles, int H) {
    if (piles.empty())
      return 0;
    int low = 1, high = *max_element(piles.begin(), piles.end()), result = INT_MAX;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (possible(piles, mid, H)) {
        result = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

