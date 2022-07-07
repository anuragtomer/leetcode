#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int numSubseq(vector<int> &nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> power(n, 1);
        power[0] = 1;
        for (int i = 1; i < n; ++i)
            power[i] = (power[i - 1] * 2) % MOD;
        int l = 0, r = n - 1, count = 0;
        while (l <= r) {
            if (nums[l] + nums[r] > target)
                r--;
            else {
                count = (count + power[r - l]) % MOD;
                l++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int target;
    nums = {3, 5, 6, 7}, target = 9;
    cout << sol.numSubseq(nums, target);
    return 0;
}
