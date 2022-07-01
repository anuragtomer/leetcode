#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool floodFill(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
      return false;
    bool returnVal = grid[i][j] == 2;
    grid[i][j] = 0;
    returnVal = floodFill(grid, i + 1, j) || returnVal;
    returnVal = floodFill(grid, i - 1, j) || returnVal;
    returnVal = floodFill(grid, i, j + 1) || returnVal;
    returnVal = floodFill(grid, i, j - 1) || returnVal;
    return returnVal;
  }

 public:
  /**
    * @param grid: an integer matrix
    * @return: an integer 
    */
  int numIslandCities(vector<vector<int>> &grid) {
    int count = 0;
    for (int H = grid.size(), i = 0; i < H; ++i) {
      for (int W = grid[0].size(), j = 0; j < W; ++j) {
        if (grid[i][j] == 1 || grid[i][j] == 2) {
          if (floodFill(grid, i, j))
            ++count;
        }
      }
    }
    return count;
  }
};

int main() {
  Solution sol;

  return 0;
}

