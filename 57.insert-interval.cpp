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

  return 0;
}
