#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int twoSumLessThanK(vector<int> A, int K) {
    int max_sum = -1;
    sort(A.begin(), A.end());
    for (int i = 0, j = A.size() - 1; i < j;) {
      int current_sum = A[i] + A[j];
      if (current_sum < K) {
        max_sum = max(max_sum, current_sum);
        ++i;
      } else {
        --j;
      }
    }
    return max_sum;
  }
};

int main() {
  Solution sol;
  assert(sol.twoSumLessThanK({34, 23, 1, 24, 75, 33, 54, 8}, 60) == 58);
  assert(sol.twoSumLessThanK({10, 20, 30}, 15) == -1);
  return 0;
}
