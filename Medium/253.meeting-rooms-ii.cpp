#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
class Solution {
   public:
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            if (a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        vector<int> result;
        bool foundOne = false;
        for (auto interval : intervals) {
            foundOne = false;
            for (auto &ends : result) {
                if (interval.start >= ends) {
                    foundOne = true;
                    ends = max(ends, interval.end);
                    break;
                }
            }
            if (!foundOne)
                result.push_back(interval.end);
        }
        return result.size();
    }
};

int main() {
    Solution sol;

    return 0;
}

