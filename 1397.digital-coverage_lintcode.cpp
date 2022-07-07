#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
* Definition of Interval:*/
class Interval {
 public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
 public:
  /**
    * @param intervals: The intervals
    * @return: The answer
    */
  int digitalCoverage(vector<Interval> &intervals) {
    int endPoint = 0;
    for (auto interval : intervals) {
      endPoint = max(endPoint, interval.end);
    }
    vector<int> sum(endPoint + 2, 0);
    for (auto interval : intervals) {
      sum[interval.start]++;
      sum[interval.end + 1]--;
    }
    int mostCovered = 0;
    for (int i = 0; i + 1 < sum.size(); ++i) {
      sum[i + 1] += sum[i];
      if (sum[i + 1] > sum[mostCovered]) {
        mostCovered = i + 1;
      }
    }
    return mostCovered;
  }
};
int main() {
  Solution sol;

  return 0;
}

