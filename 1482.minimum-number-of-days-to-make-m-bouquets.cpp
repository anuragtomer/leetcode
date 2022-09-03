#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  int minDays(vector<int> &bloomDays, int m, int k) {
    int n = bloomDays.size(), left = 1, right = 1e9;
    if (m * k > n)
      return -1;
    while (left < right) {
      int mid = (left + right) / 2, flow = 0, bouq = 0;
      for (int j = 0; j < n; ++j) {
        if (bloomDays[j] > mid) {
          flow = 0;
        } else if (++flow >= k) {
          bouq++;
          flow = 0;
        }
      }
      if (bouq < m) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
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

