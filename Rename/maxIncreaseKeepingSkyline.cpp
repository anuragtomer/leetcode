#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxRow(grid.size(), 0);
        vector<int> maxCol(grid[0].size(), 0);
        int totalIncrease = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }
        // By this time, my row and col maxes are set.
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                totalIncrease += (min(maxRow[i], maxCol[j]) - grid[i][j]);
            }
        }
        return totalIncrease;
    }
};

int main() {
    vector<vector<int>> grid(4, vector<int>(4, 0));
    grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    Solution sol;
    cout << sol.maxIncreaseKeepingSkyline(grid);
    return 0;
}