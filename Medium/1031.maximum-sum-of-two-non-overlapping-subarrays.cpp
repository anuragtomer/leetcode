#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        int res = nums[firstLen + secondLen - 1], Lmax = nums[firstLen - 1], Mmax = nums[secondLen - 1];
        for (int i = firstLen + secondLen; i < nums.size(); ++i) {
            Lmax = max(Lmax, nums[i - secondLen] - nums[i - firstLen - secondLen]);
            Mmax = max(Mmax, nums[i - firstLen] - nums[i - firstLen - secondLen]);
            res = max(res, max(Lmax + nums[i] - nums[i - secondLen], Mmax + nums[i] - nums[i - firstLen]));
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}

