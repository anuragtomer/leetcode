#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void setnearbyzero(vector<vector<char>> &grid, int i, int j, int isize, int jsize) {
        if (i < 0 || i >= isize || j < 0 || j >= jsize || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        setnearbyzero(grid, i + 1, j, isize, jsize);
        setnearbyzero(grid, i, j + 1, isize, jsize);
        setnearbyzero(grid, i - 1, j, isize, jsize);
        setnearbyzero(grid, i, j - 1, isize, jsize);
    }

   public:
    int numIslands(vector<vector<char>> &grid) {
        int islands = 0;
        int isize = grid.size();
        for (int i = 0; i < isize; i++) {
            int jsize = grid[i].size();
            for (int j = 0; j < jsize; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    setnearbyzero(grid, i, j, isize, jsize);
                }
            }
        }
        return islands;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    assert(1 == sol.numIslands(grid));
    grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    assert(3 == sol.numIslands(grid));
    return 0;
}