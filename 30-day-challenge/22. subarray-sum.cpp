#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

   public:
    /* time consuming */
    /*int subarraySum(vector<int> &nums, int k) {
        int count = 0;
        vector<vector<int>> sums(nums.size(), vector<int>(nums.size(), 0));
        sums[0][0] = nums[0];

        if (sums[0][0] == k)
            count++;
        for (int i = 1; i < nums.size(); ++i) {
            sums[0][i] = nums[i] + sums[0][i - 1];
            if (sums[0][i] == k)
                count++;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); j++) {
                sums[i][j] = nums[j] + sums[i][j - 1];
                if (sums[i][j] == k)
                    count++;
            }
        }
        return count;
    }*/
    int subarraySum(vector<int> &nums, int k) {
        int count = 0;
        unordered_map<int, int> hash;
        int m = nums.size();
        int prefix = 0;
        hash[prefix]++;
        for (int R = 0; R < m; ++R) {
            prefix += nums[R];
            int need = prefix - k;
            count += hash[need];
            hash[prefix]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    assert(2 == sol.subarraySum(nums, k));
    nums = {1, 2, 3};
    k = 3;
    assert(2 == sol.subarraySum(nums, k));
    nums = {1, 2, 1, 2, 1};
    k = 3;
    assert(4 == sol.subarraySum(nums, k));
    nums = {1};
    k = 1;
    assert(1 == sol.subarraySum(nums, k));
    return 0;
}
