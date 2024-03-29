#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
     * @param time: a string of Time
     * @return: The MaximumMoment
     */
  string MaximumMoment(string &time) {
    if (time[0] == '?') {
      time[0] = '2';
      if (time[1] != '?' && time[1] >= '4') {
        time[0] = '1';
      }
    }
    if (time[1] == '?') {
      if (time[0] == '0' || time[0] == '1') {
        time[1] = '9';
      } else if (time[0] == '2') {
        time[1] = '3';
      }
    }
    if (time[3] == '?') {
      time[3] = '5';
    }
    if (time[4] == '?')
      time[4] = '9';
    return time;
  }
};

int main() {
  Solution sol;

  return 0;
}
