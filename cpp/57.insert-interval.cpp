#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> result;
    bool inserted = false;
    for (int i = 0; i < intervals.size(); ++i) {
      if (!inserted && newInterval[0] <= intervals[i][1]) {
        inserted = true;
        if (newInterval[1] <= intervals[i][0]) {
          result.push_back(newInterval);
          --i;
        } else {
          result.push_back({min(intervals[i][0], newInterval[0]),
                            max(intervals[i][1], newInterval[1])});
        }
      } else if (!result.empty() && intervals[i][0] <= result.back()[1]) {
        result.back()[1] = max(intervals[i][1], result.back()[1]);
      } else {
        result.push_back(intervals[i]);
      }
    }
    if (!inserted)
      result.push_back(newInterval);
    return result;
  }
};
/*
 * Another solution
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    while (i < n && intervals[i][0] < newInterval[0]) {
      result.push_back(intervals[i]);
      ++i;
    }
    if (not result.empty() && result.back()[1] >= newInterval[0]) {
      result.back()[0] = min(newInterval[0], result.back()[0]);
      result.back()[1] = max(newInterval[1], result.back()[1]);
    } else {
      result.push_back(newInterval);
    }
    while (i < n) {
      if (result.back()[1] >= intervals[i][0]) {
        result.back()[0] = min(intervals[i][0], result.back()[0]);
        result.back()[1] = max(intervals[i][1], result.back()[1]);
      } else
        result.push_back(intervals[i]);
      ++i;
    }
    return result;
  }
};
*/
int main() {
  Solution sol;
  auto lMatchOutExp = [](vector<vector<int>> &out,
                         vector<vector<int>> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i].size() != exp[i].size()) {
        return false;
      }
      for (int j = 0; j < out[i].size(); ++j) {
        if (out[i][j] != exp[i][j])
          return false;
      }
    }
    return true;
  };
  vector<vector<int>> intervals;
  vector<int> newInterval;
  vector<vector<int>> output;
  vector<vector<int>> expected;
  intervals = {{1, 3}, {6, 9}}, newInterval = {2, 5},
  expected = {{1, 5}, {6, 9}};
  output = sol.insert(intervals, newInterval);
  assert(lMatchOutExp(output, expected));
  intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, newInterval = {4, 8};
  expected = {{1, 2}, {3, 10}, {12, 16}};
  output = sol.insert(intervals, newInterval);
  assert(lMatchOutExp(output, expected));
  cout << "All test cases passed.";
  return 0;
}
