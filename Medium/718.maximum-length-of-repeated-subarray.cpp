#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> dp(n1 + 1, 0);
        int result = 0;
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = 0; j < n2; ++j) {
                result = max(result, dp[j] = (nums1[i] == nums2[j] ? 1 + dp[j + 1] : 0));
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 2, 1}, nums2 = {3, 2, 1, 4, 7};
    assert(sol.findLength(nums1, nums2) == 3);
    nums1 = {0, 0, 0, 0, 0}, nums2 = {0, 0, 0, 0, 0};
    assert(sol.findLength(nums1, nums2) == 5);
    nums1 = {1, 0, 1, 0, 1}, nums2 = {0, 1, 1, 1, 1};
    assert(sol.findLength(nums1, nums2) == 2);
    return 0;
}
/*

     1 2 3 2 1
     0 0 0 0 0 0
 3
 2
 1
 4
 7
*/
