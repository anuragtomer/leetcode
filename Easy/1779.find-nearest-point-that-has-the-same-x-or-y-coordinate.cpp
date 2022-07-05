#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool isValid(vector<int> &point, int x, int y) { return (point[0] == x) || (point[1] == y); }
  int distance(vector<int> &point, int x, int y) { return abs(point[0] - x) + abs(point[1] - y); }

 public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int closestDistance = INT_MAX;
    int index = -1;
    for (int i = 0, n = points.size(); i < n; ++i) {
      if (isValid(points[i], x, y)) {
        auto thisDistance = distance(points[i], x, y);
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
