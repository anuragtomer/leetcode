#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMajorityElement(vector<int> A, int target) {
    if (lower_bound(A.begin(), A.end(), target) == A.end()) {
      return false;
    }
    return (distance(lower_bound(A.begin(), A.end(), target),
                     upper_bound(A.begin(), A.end(), target))) > (A.size() / 2);
  }
};

int main() {
  Solution sol;
  assert(sol.isMajorityElement({2, 4, 5, 5, 5, 5, 5, 6, 6}, 5));
  assert(not sol.isMajorityElement({10, 100, 101, 101}, 101));
  return 0;
}
