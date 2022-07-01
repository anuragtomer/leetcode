/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void reverse(vector<int> &nums, int beg, int end) {
        for (int i = beg; i < end; i++, end--)
            swap(nums[i], nums[end]);
    }
    
    void nextPermutation(vector<int>& nums) {
        int nusz = nums.size();
        int i = nusz - 2;
        /* 
         * Start from end and find the first increasing sequence.
         */
        for (i = nusz - 2; (i >= 0) && (nums[i] >= nums[i+1]); --i); 
        int leastGreaterIndex = i+1;
        /* 
         * Find the smallest element greater than num[i]. That should be the next greater 
         * element in lexographical order.
         */
        for (int j = i+2; j < nusz && i >= 0; j++) {
            if ((nums[j] <= nums[leastGreaterIndex]) && (nums[j] > nums[i]))
                leastGreaterIndex = j;
        }
        /*
         * Swap the next greater element with nums[i].
         */
        if (i >= 0 && i < nusz && leastGreaterIndex >= 0 && leastGreaterIndex < nusz)
            swap(nums[i], nums[leastGreaterIndex]);
        /*
         * Reverse the elements because now they would be in decreasing sequence. The next 
         * smallest number in lexo order should have smallest in front.
         */
        reverse(nums, i+1, nusz-1);
    }
};
// @lc code=end

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    Solution sol;
    sol.nextPermutation(nums);
    for (int num: nums)
        cout << num << " ";
    return 0;
}