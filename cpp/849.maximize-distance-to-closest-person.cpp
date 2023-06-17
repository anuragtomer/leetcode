#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistToClosest(vector<int> &seats) {
    int i = 0, n = seats.size();
    while (i < n && seats[i] == 0)
      ++i;
    if (i == n)
      return 0;
    int longest_dist = i, current = 0;
    while (i <= n) {
      if (i == n) {
        longest_dist = max(longest_dist, current);
      } else if (seats[i] == 1) {
        longest_dist = max(longest_dist, (current + 1) / 2);
        current = 0;
      } else {
        ++current;
      }
      ++i;
    }
    return longest_dist;
  }
};

int main() {
  Solution sol;
  vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
  assert(sol.maxDistToClosest(seats) == 2);
  seats = {1, 0, 0, 0};
  assert(sol.maxDistToClosest(seats) == 3);
  seats = {0, 1};
  assert(sol.maxDistToClosest(seats) == 1);
  seats = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1};
  assert(sol.maxDistToClosest(seats) == 3);
  return 0;
}

