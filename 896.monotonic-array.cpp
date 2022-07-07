#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param A: a array
    * @return: is it monotonous
    */
  bool isMonotonic(vector<int> &A) {
    if (A.empty() || A.size() == 1)
      return true;
    int increasing = -1;
    for (int i = 0, n = A.size(); i + 1 < n; ++i) {
      if (increasing == -1) {
        if (A[i] < A[i + 1])
          increasing = 1;
        else if (A[i] > A[i + 1])
          increasing = 0;
      } else {
        if (increasing == 1 && A[i] > A[i + 1])
          return false;
        if (increasing == 0 && A[i] < A[i + 1])
          return false;
      }
    }
    return true;
  }
};
int main() {
  Solution sol;

  return 0;
}

