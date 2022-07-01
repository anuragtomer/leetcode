#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MyCalendar {
    map<int, int> bookedIntervals;

   public:
    MyCalendar() { bookedIntervals.clear(); }

    bool book(int start, int end) {
        auto intersection = bookedIntervals.upper_bound(start);
        if (intersection != bookedIntervals.end() && (*intersection).second < end)
            return false;
        bookedIntervals.insert({end, start});
        return true;
    }
};
/*
class MyCalendar {
  vector<int> starts, ends;
public:
  MyCalendar() {
    starts.clear(); ends.clear();
  }

  bool book(int start, int end) {
    auto intersection = upper_bound(ends.begin(), ends.end(), start);
    if (intersection != ends.end()) {
      int diff = intersection - ends.begin();
      if (*(starts.begin() + diff) < end)
        return false;
      else {
        starts.insert(starts.begin() + diff, start);
        ends.insert(intersection, end);
        return true;
      }
    }
    starts.push_back(start);
    ends.push_back(end);
    return true;
  }
};

 */
int main() {
    MyCalendar sol;

    return 0;
}

