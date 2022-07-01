#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, pair<int, int>> pi;

class Solution {
    // /** Timed out solution.
    /* int minPathSum(vector<vector<int>> &grid, int i, int j, int isize, int jsize) {
        if (i == isize && j != jsize)
            return grid[i][j] + minPathSum(grid, i, j + 1, isize, grid[i].size() - 1);
        else if (i == isize && j == jsize)
            return grid[i][j];
        else if (i != isize && j == jsize)
            return grid[i][j] + minPathSum(grid, i + 1, j, isize, grid[i].size() - 1);
        return grid[i][j] + min(minPathSum(grid, i, j + 1, isize, grid[i].size() - 1),
                                minPathSum(grid, i + 1, j, isize, grid[i].size() - 1));
    }

   public:
    int minPathSum(vector<vector<int>> &grid) {
        return minPathSum(grid, 0, 0, grid.size() - 1, grid[0].size() - 1);
    } */

   public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<vector<int>> distance(grid.size(), vector<int>(grid[grid.size() - 1].size(), INT_MAX));
        distance[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++)
            distance[i][0] = grid[i][0] + distance[i - 1][0];
        for (int j = 1; j < grid[0].size(); ++j)
            distance[0][j] = grid[0][j] + distance[0][j - 1];
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[i].size(); ++j) {
                distance[i][j] = min(distance[i - 1][j], distance[i][j - 1]) + grid[i][j];
            }
        }
        return distance[grid.size() - 1][grid[grid.size() - 1].size() - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    assert(7 == sol.minPathSum(grid));
    cout << "First passed.\n";
    grid = {{5, 0, 1, 1, 2, 1, 0, 1, 3, 6, 3, 0, 7, 3, 3, 3, 1}, {1, 4, 1, 8, 5, 5, 5, 6, 8, 7, 0, 4, 3, 9, 9, 6, 0},
            {2, 8, 3, 3, 1, 6, 1, 4, 9, 0, 9, 2, 3, 3, 3, 8, 4}, {3, 5, 1, 9, 3, 0, 8, 3, 4, 3, 4, 6, 9, 6, 8, 9, 9},
            {3, 0, 7, 4, 6, 6, 4, 6, 8, 8, 9, 3, 8, 3, 9, 3, 4}, {8, 8, 6, 8, 3, 3, 1, 7, 9, 3, 3, 9, 2, 4, 3, 5, 1},
            {7, 1, 0, 4, 7, 8, 4, 6, 4, 2, 1, 3, 7, 8, 3, 5, 4}, {3, 0, 9, 6, 7, 8, 9, 2, 0, 4, 6, 3, 9, 7, 2, 0, 7},
            {8, 0, 8, 2, 6, 4, 4, 0, 9, 3, 8, 4, 0, 4, 7, 0, 4}, {3, 7, 4, 5, 9, 4, 9, 7, 9, 8, 7, 4, 0, 4, 2, 0, 4},
            {5, 9, 0, 1, 9, 1, 5, 9, 5, 5, 3, 4, 6, 9, 8, 5, 6}, {5, 7, 2, 4, 4, 4, 2, 1, 8, 4, 8, 0, 5, 4, 7, 4, 7},
            {9, 5, 8, 6, 4, 4, 3, 9, 8, 1, 1, 8, 7, 7, 3, 6, 9}, {7, 2, 3, 1, 6, 3, 6, 6, 6, 3, 2, 3, 9, 9, 4, 4, 8}};
    assert(83 == sol.minPathSum(grid));
    cout << "Second passed.\n";
    grid = {
        {7, 1, 3, 5, 8, 9, 9, 2, 1, 9, 0, 8, 3, 1, 6, 6, 9, 5}, {9, 5, 9, 4, 0, 4, 8, 8, 9, 5, 7, 3, 6, 6, 6, 9, 1, 6},
        {8, 2, 9, 1, 3, 1, 9, 7, 2, 5, 3, 1, 2, 4, 8, 2, 8, 8}, {6, 7, 9, 8, 4, 8, 3, 0, 4, 0, 9, 6, 6, 0, 0, 5, 1, 4},
        {7, 1, 3, 1, 8, 8, 3, 1, 2, 1, 5, 0, 2, 1, 9, 1, 1, 4}, {9, 5, 4, 3, 5, 6, 1, 3, 6, 4, 9, 7, 0, 8, 0, 3, 9, 9},
        {1, 4, 2, 5, 8, 7, 7, 0, 0, 7, 1, 2, 1, 2, 7, 7, 7, 4}, {3, 9, 7, 9, 5, 8, 9, 5, 6, 9, 8, 8, 0, 1, 4, 2, 8, 2},
        {1, 5, 2, 2, 2, 5, 6, 3, 9, 3, 1, 7, 9, 6, 8, 6, 8, 3}, {5, 7, 8, 3, 8, 8, 3, 9, 9, 8, 1, 9, 2, 5, 4, 7, 7, 7},
        {2, 3, 2, 4, 8, 5, 1, 7, 2, 9, 5, 2, 4, 2, 9, 2, 8, 7}, {0, 1, 6, 1, 1, 0, 0, 6, 5, 4, 3, 4, 3, 7, 9, 6, 1, 9}};
    assert(85 == sol.minPathSum(grid));
    cout << "Third passed.\n";
    return 0;
}