#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
     * Idea is to use Kadane's algorithm.
     * First find maxSum till each index using kadane's algo.
     * Then get the sum of first k elements.
     * Using sliding window of size k, add one next element to sum, and subtract first element from sum
     * and see if this sum changes your result.
     * Also, see if this result would be greater if you took the max sum till i-k elements.
     */
    int maxSumSubArray(vector<int> arr, int k) {
        auto n = arr.size();
        vector<int> maxSum = vector<int>(n, 0);
        maxSum[0] = arr[0];
        int currMax = arr[0];
        for (int i = 1; i < n; ++i) {
            currMax = max(arr[i], currMax + arr[i]);
            maxSum[i] = currMax;
        }

        int sum = 0;
        for (int i = 0; i < k; ++i)
            sum += arr[i];

        int result = sum;
        for (int i = k; i < n; ++i) {
            sum = sum + arr[i] - arr[i - k];
            result = max(result, sum);
            result = max(result, sum + maxSum[i - k]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 7, -9, 3, -4, 2, 1, -8, 9, 10};
    assert(16 == sol.maxSumSubArray(arr, 5));
    arr = {-4, -2, 1, -3};
    assert(-1 == sol.maxSumSubArray(arr, 2));
    arr = {1, 1, 1, 1, 1, 1};
    assert(6 == sol.maxSumSubArray(arr, 6));
    return 0;
}

