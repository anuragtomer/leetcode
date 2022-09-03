#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int loop_through(const vector<int> &bloomDay, const int &m, const int &k,
                   const int &mid) {
    int count = 0, bou = 0;
    for (int i = 0; i < bloomDay.size(); ++i) {
      if (bloomDay[i] <= mid) {
        ++count;
        if (count == k) {
          count = 0;
          ++bou;
          if (bou == m) {
            return bou;
          }
        }
      } else {
        count = 0;
      }
    }
    return bou;
  }
  int binary_search(const vector<int> &bloomDay, const int &m, const int &k,
                    int &low, int &high) {
    int result = high;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int bou = loop_through(bloomDay, m, k, mid);
      if (bou == m) {
        result = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return result;
  }

 public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (n < m * k)
      return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    return binary_search(bloomDay, m, k, low, high);
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

