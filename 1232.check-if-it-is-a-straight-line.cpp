class Solution {
  float getSlope(int x1, int y1, int x2, int y2) {
    return static_cast<float>(y2 - y1) / static_cast<float>(x2 - x1);
  }

 public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    if (coordinates.size() <= 2)
      return true;
    sort(coordinates.begin(), coordinates.end(),
         [](vector<int> &a, vector<int> &b) {
           return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });
    float slope = getSlope(coordinates[0][0], coordinates[0][1],
                           coordinates[1][0], coordinates[1][1]);
    for (int i = 1; i < coordinates.size() - 1; ++i) {
      if (slope != getSlope(coordinates[i][0], coordinates[i][1],
                            coordinates[i + 1][0], coordinates[i + 1][1]))
        return false;
    }
    return true;
  }
};
