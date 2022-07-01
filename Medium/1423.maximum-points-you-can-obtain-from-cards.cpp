#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        int size = n - k;
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0), sum = 0;
        int minSum = totalSum;
        if (size == 0)
            return minSum;
        for (int left = 0, right = 0; right < n; ++right) {
            sum += cardPoints[right];
            if (right - left + 1 >= size) {
                minSum = min(minSum, sum);
                sum -= cardPoints[left];
                ++left;
            }
        }
        return totalSum - minSum;
    }
};

int main() {
    Solution sol;

    return 0;
}

