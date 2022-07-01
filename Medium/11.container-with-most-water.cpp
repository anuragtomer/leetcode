/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * Note: You may not slant the container and n is at least 2.
 *
 * Example:
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /*
     * Algo:
     * Get the max water by keeping 2 pointers - 1st at beginning, 2nd at end.
     * Now, increase/decrease the pointers until you find a height that might get you more area (new
     * height is greater than previous heights).
     */
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1; // 2 pointers inited to first and last.
        int maxWater = 0;
        while(i < j) {
            int minH = min(height[i], height[j]); // Calculate the lower of the two height.
            maxWater = max(maxWater, minH * (j - i)); // Calculate the max area between i and j.
            while(height[i] <= minH && i < j) i++; // Search for a higher building than current i.
            while(height[j] <= minH && i < j) j--; // Search for a higher building than current j.
        }
        return maxWater;
    }
};
// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i)
        cin >> height[n];
    cout << sol.maxArea(height) << endl;
    return 0;
}