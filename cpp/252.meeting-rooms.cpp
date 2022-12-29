#include <algorithm>
#include <cassert>
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
  bool canAttendMeetings(vector<Interval> intervals) {
    sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
      return a.start == b.start ? a.end > b.end : a.start < b.start;
    });
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start <= intervals[i - 1].end) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  assert(not sol.canAttendMeetings(
    vector<Interval>{Interval(0, 30), Interval(5, 10), Interval(15, 20)}));

  assert(
    sol.canAttendMeetings(vector<Interval>{Interval(5, 8), Interval(9, 15)}));
  return 0;
}
