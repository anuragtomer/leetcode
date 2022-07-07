#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int last = 0, count = 0;
        for (int i = 1, n = intervals.size(); i < n; ++i) {
            if (intervals[i][0] >= intervals[last][1]) {
                // All good.
                last = i;
            } else {
                ++count;
                // I have to discard one of them. Discard which finishes
                // first so that I can accomodate more intervals.
                if (intervals[i][1] < intervals[last][1]) {
                    // discarding previous interval
                    last = i;
                } else {
                    // Nothing to do here. last stays as is. We have discarded i'th interval.
                    ;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    return 0;
}

