#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int fixedPoint(vector<int> A) {
    int lb = 0, ub = A.size();
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (A[mid] == mid)
        return mid;
      else if (A[mid] < mid)
        lb = mid + 1;
      else
        ub = mid;
    }
    return -1;
  }
};

int main() {
  Solution sol;

  assert(sol.fixedPoint({-10, -5, 0, 3, 7}) == 3);
  assert(sol.fixedPoint({0, 2, 5, 8, 17}) == 0);
  assert(sol.fixedPoint({-10, -5, 3, 4, 7, 9}) == -1);

  return 0;
}
