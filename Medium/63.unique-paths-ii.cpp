#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int H = obstacleGrid.size(), W = obstacleGrid[0].size();
        vector<vector<int>> pathGrid(H, vector<int>(W, 0));
        for (int i = 0; i < H && obstacleGrid[i][0] != 1; ++i)
            pathGrid[i][0] = 1;
        for (int j = 0; j < W && obstacleGrid[0][j] != 1; ++j)
            pathGrid[0][j] = 1;
        for (int i = 1; i < H; ++i) {
            for (int j = 1; j < W; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    pathGrid[i][j] = pathGrid[i - 1][j] + pathGrid[i][j - 1];
                }
            }
        }
        return pathGrid.back().back();
    }
};

int main() {
    Solution sol;

    return 0;
}

