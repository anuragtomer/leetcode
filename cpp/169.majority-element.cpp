/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    if (nums.empty())
      return 0;
    pair<int, int> majority_element = {nums.front(), 1};
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == majority_element.first)
        majority_element.second++;
      else {
        majority_element.second--;
        if (majority_element.second < 0) {
          majority_element = {nums[i], 1};
        }
      }
    }
    return majority_element.first;
  }
};
// @lc code=end

int main() {
  Solution sol;
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << sol.majorityElement(nums);
  return 0;
}
