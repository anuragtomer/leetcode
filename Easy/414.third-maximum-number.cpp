#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int thirdMax(vector<int> &nums) {
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
    for (auto num : nums) {
      if (num >= first) {
        if (num == first)
          continue;
        third = second;
        second = first;
        first = num;
      } else if (num >= second) {
        if (num == second)
          continue;
        third = second;
        second = num;
      } else if (num >= third) {
        if (num == third)
          continue;
        third = num;
      }
    }
    return third == LONG_MIN ? first : third;
  }
};

int main() {
  Solution sol;

  return 0;
}

