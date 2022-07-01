#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int closestDistance = INT_MAX;
    int index = -1;
    for (int i = 0, n = points.size(); i < n; ++i) {
      if (points[i][0] == x || points[i][1] == y) {
        auto thisDistance = abs(points[i][0] - x) + abs(points[i][1] - y);
        if (closestDistance > thisDistance) {
          closestDistance = thisDistance;
          index = i;
        }
      }
    }
    return index;
  }
};

int main() {
  Solution sol;

  return 0;
}

