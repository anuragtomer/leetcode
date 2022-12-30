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
  int minMeetingRooms(vector<Interval> intervals) {
    vector<int> last_time;
    sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
      return a.start == b.start ? a.end > b.end : a.start < b.start;
    });
    for (auto &inter : intervals) {
      bool found = false;
      for (int i = 0; i < last_time.size() && not found; ++i) {
        if (last_time[i] <= inter.start) {
          last_time[i] = inter.end;
          found = true;
        }
      }
      if (not found) {
        last_time.push_back(inter.end);
      }
    }
    return last_time.size();
  }
};

int main() {
  Solution sol;
  assert(sol.minMeetingRooms(vector<Interval>{Interval(0, 30), Interval(5, 10),
                                              Interval(15, 20)}) == 2);
  assert(sol.minMeetingRooms(vector<Interval>{Interval(2, 7)}) == 1);
  return 0;
}
