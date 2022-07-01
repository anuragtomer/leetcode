#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param A: An array of Integer
    * @return: an integer
    */
  int longestIncreasingContinuousSubsequence(vector<int> &A) {
    int longest = A.empty() ? 0 : 1, current = 1;
    bool increasing = false;
    for (int i = 1, n = A.size(); i < n; ++i) {
      if (A[i - 1] < A[i]) {
        if (increasing)
          current++;
        else {
          increasing = true;
          current = 2;
        }
        longest = max(longest, current);
      } else if (A[i - 1] > A[i]) {
        if (!increasing)
          ++current;
        else {
          increasing = false;
          current = 2;
        }
        longest = max(longest, current);
      }
    }
    return longest;
  }
};
int main() {
  Solution sol;

  return 0;
}

