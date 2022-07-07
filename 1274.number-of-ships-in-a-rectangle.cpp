#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Sea {
 public:
  bool hasShips(vector<int> &topRight, vector<int> &bottomLeft) { return true; }
};
class Solution {
 public:
  int countShips(Sea sea, vector<int> &topRight, vector<int> &bottomLeft) {
    if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1])
      return sea.hasShips(topRight, bottomLeft) ? 1 : 0;
    if (topRight[0] == bottomLeft[0]) {
      int midY = bottomLeft[1] + (topRight[1] - bottomLeft[1]) / 2;
      vector<int> topRightMid = {topRight[0], midY};
      vector<int> bottomLeftMid = {bottomLeft[0], midY + 1};
      int ships = 0;
      if (sea.hasShips(topRightMid, bottomLeft))
        ships += countShips(sea, topRightMid, bottomLeft);
      if (sea.hasShips(topRight, bottomLeftMid))
        ships += countShips(sea, topRight, bottomLeftMid);
      return ships;
    }
    if (topRight[1] == bottomLeft[1]) {
      int midX = bottomLeft[0] + (topRight[0] - bottomLeft[0]) / 2;
      vector<int> topRightMid = {midX, topRight[1]};
      vector<int> bottomLeftMid = {midX + 1, bottomLeft[1]};
      int ships = 0;
      if (sea.hasShips(topRightMid, bottomLeft))
        ships += countShips(sea, topRightMid, bottomLeft);
      if (sea.hasShips(topRight, bottomLeftMid))
        ships += countShips(sea, topRight, bottomLeftMid);
      return ships;
    }
    int midX = bottomLeft[0] + (topRight[0] - bottomLeft[0]) / 2;
    int midY = bottomLeft[1] + (topRight[1] - bottomLeft[1]) / 2;
    vector<int> topRight1 = {midX, midY};
    vector<int> topRight2 = {topRight[0], midY};
    vector<int> topRight3 = {midX, topRight[1]};
    vector<int> topRight4 = topRight;
    vector<int> bottomLeft1 = bottomLeft;
    vector<int> bottomLeft2 = {midX + 1, bottomLeft[1]};
    vector<int> bottomLeft3 = {bottomLeft[0], midY + 1};
    vector<int> bottomLeft4 = {midX + 1, midY + 1};
    int ships = 0;
    if (sea.hasShips(topRight1, bottomLeft1))
      ships += countShips(sea, topRight1, bottomLeft1);
    if (sea.hasShips(topRight2, bottomLeft2))
      ships += countShips(sea, topRight2, bottomLeft2);
    if (sea.hasShips(topRight3, bottomLeft3))
      ships += countShips(sea, topRight3, bottomLeft3);
    if (sea.hasShips(topRight4, bottomLeft4))
      ships += countShips(sea, topRight4, bottomLeft4);
    return ships;
  }
};

int main() {
  Solution sol;
  Sea sea;
  vector<int> topRight = {0, 0};
  vector<int> bottomLeft = {4, 4};
  cout << sol.countShips(sea, topRight, bottomLeft);
  return 0;
}

