#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLengthOfLCIS(vector<int> &A) {
    int longest = A.empty() ? 0 : 1, current = 1;
    for (int i = 1, n = A.size(); i < n; ++i) {
      if (A[i - 1] < A[i]) {
        current++;
        longest = max(longest, current);
      } else
        current = 1;
    }
    return longest;
  }
};
int main() {
  Solution sol;

  return 0;
}

