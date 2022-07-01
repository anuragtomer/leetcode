/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        vector<string> output;
        string str(to_string(nums[0]));
        int prev = 0;
        int i = 1;
        for (i = 1; i < nums.size(); ++i) {
            if (nums[i-1] + 1 == nums[i]) {
                continue;
            }
            if (prev != i-1) {
                str += "->";
                str += to_string(nums[i-1]);
            }
            prev = i;
            output.push_back(str);
            str.clear();
            str += to_string(nums[i]);
        }
        if (prev != i-1) {
            str += "->";
            str += to_string(nums[i-1]);
        }
        output.push_back(str);
        return output;
    }
};
// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    vector<string> output = sol.summaryRanges(nums);
    for (auto str: output)
        cout << str << "\t";
    return 0;
}