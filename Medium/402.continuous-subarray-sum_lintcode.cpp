#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> continuousSubarraySum(vector<int> &A) {
    if (A.empty())
      return {};
    int maxSum = A[0], currentSum = A[0];
    vector<int> result = {0, 0}, current = {0, 0};
    for (int i = 1; i < A.size(); ++i) {
      if (currentSum + A[i] >= A[i]) {
        currentSum += A[i];
        current.back() = i;
      } else {
        currentSum = A[i];
        current = {i, i};
      }
      if (maxSum < currentSum) {
        maxSum = currentSum;
        result = current;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;

  return 0;
}

