#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool possibleShipping(vector<int> &weights, int sum, int d) {
    int days = 0, currentSum = 0;
    for (auto weight : weights) {
      if (currentSum + weight <= sum) {
        currentSum += weight;
      } else {
        ++days;
        currentSum = weight;
      }
    }
    return days < d;
  }

 public:
  int shipWithinDays(vector<int> &weights, int D) {
    int minSum = INT_MIN, maxSum = 0;
    for (auto weight : weights) {
      minSum = max(minSum, weight);
      maxSum += weight;
    }
    int result = INT_MAX;
    while (minSum <= maxSum) {
      int mid = minSum + (maxSum - minSum) / 2;
      if (possibleShipping(weights, mid, D)) {
        result = min(result, mid);
        maxSum = mid - 1;
      } else {
        minSum = mid + 1;
      }
    }
    return result;
  }
};
int main() {
  Solution sol;
  vector<int> weights;
  int days;
  weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, days = 5;
  assert(sol.shipWithinDays(weights, days) == 15);

  weights = {3, 2, 2, 4, 1, 4}, days = 3;
  assert(sol.shipWithinDays(weights, days) == 6);

  weights = {1, 2, 3, 1, 1}, days = 4;
  assert(sol.shipWithinDays(weights, days) == 3);
  return 0;
}
