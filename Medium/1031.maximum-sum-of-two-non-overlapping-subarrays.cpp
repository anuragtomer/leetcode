#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int helper(vector<int> &nums, int firstLen, int secondLen, int n) {
        vector<int> leftSum(n + 1), rightSum(n + 1);
        int sumL = 0, sumR = 0;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            sumL += nums[i];
            sumR += nums[j];
            leftSum[i + 1] = max(leftSum[i], sumL);
            rightSum[j] = max(rightSum[j + 1], sumR);
            if (i + 1 >= firstLen)
                sumL -= nums[i + 1 - firstLen];
            if (i + 1 >= secondLen)
                sumR -= nums[j - 1 + secondLen];
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
            result = max(result, leftSum[i] + rightSum[i]);
        return result;
    }

   public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen, nums.size()), helper(nums, secondLen, firstLen, nums.size()));
    }
};

int main() {
    Solution sol;

    return 0;
}

