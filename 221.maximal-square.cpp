#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    /* Too many no of lines.
     int maximalSquare(vector<vector<char>> &matrix) {
         if (matrix.size() == 0)
             return 0;
         vector<vector<int>> sumMatrix(matrix.size(), vector<int>(matrix[0].size(), 0));
         int maxsquare = 0;
         for (int i = 0; i < matrix.size(); i++) {
             sumMatrix[i][0] = matrix[i][0] == '1' ? 1 : 0;
             maxsquare = max(maxsquare, sumMatrix[i][0]);
         }

         for (int i = 0; i < matrix[0].size(); i++) {
             sumMatrix[0][i] = matrix[0][i] == '1' ? 1 : 0;
             maxsquare = max(maxsquare, sumMatrix[0][i]);
         }

         for (int i = 1; i < matrix.size(); i++) {
             for (int j = 1; j < matrix[i].size(); j++) {
                 if (matrix[i][j] == '1') {
                     sumMatrix[i][j] = 1 + min(min(sumMatrix[i][j - 1], sumMatrix[i - 1][j]), sumMatrix[i - 1][j - 1]);
                     maxsquare = max(maxsquare, sumMatrix[i][j]);
                 }
             }
         }
         return maxsquare * maxsquare;
     }*/
    // Lesser no of lines. Credit: Errichto
    int maximalSquare(vector<vector<char>> &matrix) {
        int H = matrix.size();
        if (H == 0 || matrix[0].size() == 0)
            return 0;
        int W = matrix[0].size();
        vector<vector<int>> dp(H, vector<int>(W));
        int answer = 0;
        for (int row = 0; row < H; row++) {
            for (int col = 0; col < W; col++) {
                if (matrix[row][col] == '1') {
                    dp[row][col] = 1;
                    if (row > 0 && col > 0)
                        dp[row][col] += min({dp[row - 1][col - 1], dp[row][col - 1], dp[row - 1][col]});
                    answer = max(answer, dp[row][col]);
                }
            }
        }
        return answer * answer;
    }
};
int main() {
    Solution sol;
    vector<vector<char>> matrix;
    matrix = {
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    assert(4 == sol.maximalSquare(matrix));
    return 0;
}
