#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param A: an array
    * @param B: an array
    * @return: dot product of two array
    */
  int dotProduct(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size() || A.empty())
      return -1;
    int prod = 0;
    for (int i = 0; i < A.size(); ++i)
      prod += A[i] * B[i];
    return prod;
  }
};
int main() {
  Solution sol;

  return 0;
}

