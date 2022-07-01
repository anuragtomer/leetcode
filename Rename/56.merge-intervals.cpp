/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
        }
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
    for (auto outp: output)
        cout << outp[0] << " " << outp[1] << "\t";
    return 0;
}