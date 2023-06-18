#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  int minDays(vector<int> &bloomDays, int m, int k) {
    int n = bloomDays.size();
    int min_days = *min_element(bloomDays.begin(), bloomDays.end());
    int max_days = *max_element(bloomDays.begin(), bloomDays.end());
    int result = -1;
    while (min_days <= max_days) {
      int mid = (min_days + max_days) / 2, flowers = 0, bouquets = 0;
      for (int j = 0; j < n; ++j) {
        if (bloomDays[j] > mid) {
          flowers = 0;
        } else if (++flowers >= k) {
          bouquets++;
          flowers = 0;
        }
      }
      if (bouquets < m) {
        min_days = mid + 1;
      } else {
        result = mid;
        max_days = mid - 1;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> bloomDay = {1, 10, 3, 10, 2};
  int m = 3, k = 1;
  assert(3 == sol.minDays(bloomDay, m, k));
  bloomDay = {1, 10, 3, 10, 2}, m = 3, k = 2;
  assert(-1 == sol.minDays(bloomDay, m, k));
  bloomDay = {7, 7, 7, 7, 12, 7, 7}, m = 2, k = 3;
  assert(12 == sol.minDays(bloomDay, m, k));
  bloomDay = {1, 2, 4, 9, 3, 4, 1}, m = 2, k = 2;
  assert(4 == sol.minDays(bloomDay, m, k));
  return 0;
}
