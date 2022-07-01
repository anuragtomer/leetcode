#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canPartitionKSubsets(vector<int> &nums, int K) {
        int N = nums.size();
        if (K == 1)
            return true;
        if (N < K)
            return false;
        int sum = 0, maxElement = -1;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            maxElement = max(maxElement, nums[i]);
        }
        if (sum % K != 0 || maxElement > sum / K)
            return false;

        int subset = sum / K;
        vector<int> subsetSum(K, 0);
        vector<bool> taken(N, false);

        subsetSum[0] = nums[N - 1];
        taken[N - 1] = true;

        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
    }

    bool canPartitionKSubsets(vector<int> &nums, vector<int> subsetSum, vector<bool> taken, int subset, int K, int N,
                              int curIdx, int limitIdx) {
        if (subsetSum[curIdx] == subset) {
            if (curIdx == K - 2)
                return true;
            return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
        }

        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i])
                continue;
            int tmp = subsetSum[curIdx] + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                if (nxt)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    assert(sol.canPartitionKSubsets(nums, k));
    nums = {1, 2, 3, 4}, k = 3;
    assert(!sol.canPartitionKSubsets(nums, k));
    nums = {10, 10, 10, 7, 7, 7, 7, 7, 7, 6, 6, 6}, k = 3;
    assert(sol.canPartitionKSubsets(nums, k));
    nums = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3}, k = 8;
    assert(!sol.canPartitionKSubsets(nums, k));
    return 0;
}

