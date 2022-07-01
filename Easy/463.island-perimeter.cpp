#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int checkNeighbor(vector<vector<int>> &grid, int i, int j) {
        int count = 0;
        if (i == 0)
            count++;
        else if (grid[i - 1][j] == 0)
            count++;

        if (j == 0)
            count++;
        else if (grid[i][j - 1] == 0)
            count++;

        if (i == grid.size() - 1)
            count++;
        else if (grid[i + 1][j] == 0)
            count++;

        if (j == grid[i].size() - 1)
            count++;
        else if (grid[i][j + 1] == 0)
            count++;

        return count;
    }

   public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    count += checkNeighbor(grid, i, j);
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    assert(16 == sol.islandPerimeter(grid));
    return 0;
}
