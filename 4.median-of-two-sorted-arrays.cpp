/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
class Solution {
public:
    int findkthInSorted(vector<int> nums1, 
                    vector<int> nums2, 
                    int k) {
        if (nums1.size() == 0)
            return nums2[k];
        if (nums2.size() == 0)
            return nums1[k];
        if (k == 0)
            return min(nums1[0], nums2[0]);
        else {
            int mid1 = nums1.size() / 2;
            int mid2 = nums2.size() / 2;
            if (mid1 + mid2 < k) {
                /* 
                 * This means the elemnt we are interested in is in the other half.
                 * So, discard the lower half of the 'would-be' combined sorted array.
                 */
                if (nums1[mid1] < nums2[mid2]) {
                    nums1.erase(nums1.begin(), nums1.begin() + mid1 + 1);
                    /* 
                     * Since we have removed some elements from the beginning of 'would-be' sorted
                     * array, we must reduce our desired k.
                     */
                    k = k - (mid1 + 1);
                } else {
                    nums2.erase(nums2.begin(), nums2.begin() + mid2 + 1);
                    k = k - (mid2 + 1);
                }
                assert(k >= 0);
            } else if (mid1 + mid2 >= k) {
                /*
                 * Discard higher end elements.
                 * Dont need them. We have way too many already
                 */
                if (nums1[mid1] > nums2[mid2])
                    nums1.erase(nums1.begin() + mid1, nums1.end());
                else
                    nums2.erase(nums2.begin() + mid2, nums2.end());
            }
            return findkthInSorted(nums1,nums2, k);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        vector<int> mid(2, 0);
        if (size % 2 == 0) {
            mid[0] = (size/2) - 1;
        } else {
            mid[0] = size/2;
        }
        mid[1] = size/2;
        int a = findkthInSorted(nums1, nums2, mid[0]);
        if (mid[0] == mid[1])
            return a;
        int b = findkthInSorted(nums1, nums2, mid[1]); 
        return (a + b) / 2.0;
    }
};

int main() {
    vector<int> nums1 = {1,2,4,8,16,32,64,128};
    vector<int> nums2 = {3,5,6,7};
    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2);
    return 0;
}
// @lc code=end

