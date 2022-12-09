#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k)
                maxLen = i + 1;
            if (hash.find(sum) == hash.end())
                hash[sum] = i;
            if (hash.find(sum - k) != hash.end()) {
                maxLen = max(maxLen, i - hash[sum - k]);
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, -1, 5, -2, 3};
    assert(4 == sol.maxSubArrayLen(nums, 3));
    return 0;
}

