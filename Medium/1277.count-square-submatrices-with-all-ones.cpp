#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
   public:
    int countSquares(vector<vector<int>> &matrix) {
        int H = matrix.size(), W = matrix[0].size();
        vector<vector<int>> dp = matrix;
        for (int r = 1; r < H; ++r) {
            for (int c = 1; c < W; ++c) {
                if (dp[r][c] != 0 && dp[r - 1][c] != 0 && dp[r][c - 1] != 0 && dp[r - 1][c - 1] != 0) {
                    dp[r][c] = 1 + min(dp[r - 1][c], min(dp[r][c - 1], dp[r - 1][c - 1]));
                }
            }
        }
        // Sum individual points
        int count = 0;
        for (auto row : dp) {
            for (auto val : row) {
                count += val;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    assert(sol.countSquares(matrix) == 15);
    return 0;
}

