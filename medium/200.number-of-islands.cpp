#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
    void markvisited(vector< vector<char> > &grid, int i, int j) {
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid[i].size() && grid[i][j] == '1') {
            grid[i][j] = '2';
            markvisited(grid, i-1, j);
            markvisited(grid, i, j-1);            
            markvisited(grid, i+1, j);
            markvisited(grid, i, j+1);
        }
    }

public:
    int numIslands(vector< vector<char> >& grid) {
        int count = 0;
        int n = grid.size();
        
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == '1') {
                    markvisited(grid, i, j);
                    count++;
                }
        return count;
    }
};
// @lc code=end


int main() {
    Solution sol;
    vector< vector<char> > grid = {{'1', '1', '1', '1', '0'}, 
                                   {'1', '1', '0', '1', '0'}, 
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '0', '0', '0'}};
    assert(1 == sol.numIslands(grid));// << "\n";
    grid = {{'1', '1', '0', '0', '0'}, 
            {'1', '1', '0', '0', '0'}, 
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};
    assert(3 == sol.numIslands(grid));
    cout << "Test cases passed\n";
    return 0;
}
