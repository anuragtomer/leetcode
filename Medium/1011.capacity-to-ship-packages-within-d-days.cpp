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

    return 0;
}

