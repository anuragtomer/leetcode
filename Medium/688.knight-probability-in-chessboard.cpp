#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    double grid[26][26][101];

    double knightProbability(int n, int k, int row, int column) {
        if (row >= n || column >= n || row < 0 || column < 0)
            return 0; // out of bounds
        if (k == 0)
            return 1; // no more moves needed
        if (grid[row][column][k] > 0)
            return grid[row][column][k];

        double result = 0;
        result += 0.125 * knightProbability(n, k - 1, row - 1, column - 2);
        result += 0.125 * knightProbability(n, k - 1, row - 1, column + 2);
        result += 0.125 * knightProbability(n, k - 1, row + 1, column - 2);
        result += 0.125 * knightProbability(n, k - 1, row + 1, column + 2);
        result += 0.125 * knightProbability(n, k - 1, row - 2, column - 1);
        result += 0.125 * knightProbability(n, k - 1, row - 2, column + 1);
        result += 0.125 * knightProbability(n, k - 1, row + 2, column - 1);
        result += 0.125 * knightProbability(n, k - 1, row + 2, column + 1);

        grid[row][column][k] = result; // mark as visited

        return result;
    }
};
int main() {
    Solution sol;
    cout << sol.knightProbability(3, 2, 0, 0);
    return 0;
}

