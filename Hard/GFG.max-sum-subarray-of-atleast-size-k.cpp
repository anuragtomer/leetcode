#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSumSubArray(vector<int> arr, int k) {
        vector<int> prefixSum(arr.size() + 1);
        prefixSum[0] = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            prefixSum[i + 1] = arr[i] + prefixSum[i];
        }
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + k; j <= arr.size(); ++j) {
                maxSum = max(maxSum, prefixSum[j] - prefixSum[i]);
            }
        }
        return maxSum;
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

