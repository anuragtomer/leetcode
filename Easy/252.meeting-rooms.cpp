#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of Interval:*/
struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
   public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &interval) {
        if (interval.size() <= 1)
            return true;
        sort(interval.begin(), interval.end(), [](Interval &a, Interval &b) {
            if (a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        for (int i = 0; i < interval.size() - 1; ++i) {
            if (interval[i].end > interval[i + 1].start)
                return false;
        }
        return true;
    }
};
int main() {
    Solution sol;

    return 0;
}

