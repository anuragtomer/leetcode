/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // Another approach. Simpler to code.
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> output;
        for (auto interval : intervals) {
            if (output.empty()) {
                output.push_back(interval);
            } else {
                if (output.back()[1] >= interval[0]) {
                    output.back()[1] = max(output.back()[1], interval[1]);
                } else {
                    output.push_back(interval);
                }
            }
        }
        /*
        if (intervals.size() == 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        vector<int> temp(2, 0);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        int outputSz = 0;
        output.push_back(temp);
        for (unsigned int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= output[outputSz][1]) {
                output[outputSz][1] = max(intervals[i][1], output[outputSz][1]);
            } else {
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
                output.push_back(temp);
                outputSz++;
            }
        }*/
        /* Alternatively:
        vector<vector<int>> output;
        vector<int> temp(2, 0);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        for (unsigned int i = 1; i < intervals.size(); ++i) {
            if (temp[1] >= interval[i][0]) {
                // Keep updating the end of the interval.
                temp[1] = max(intervals[i][1], temp[1]);
            } else {
                // Add temp to output, Start new interval.
                output.push_back(temp);
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
        }
        output.push_back(temp);
        */
        return output;
    }
};

// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i)
        cin >> intervals[i][0] >> intervals[i][1];
    vector<vector<int>> output = sol.merge(intervals);
    for (auto outp : output)
        cout << outp[0] << " " << outp[1] << "\t";
    return 0;
}
