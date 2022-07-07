#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int findLongest(const vector<vector<int>> &matrix, int r, int c, vector<vector<bool>> &visitedMatrix, int maxLen) {
        if (r + 1 <= matrix.size() - 1 && visitedMatrix[r + 1][c] == false && matrix[r + 1][c] > matrix[r][c]) {
            visitedMatrix[r + 1][c] = true;
            maxLen = max(maxLen, findLongest(matrix, r + 1, c, visitedMatrix, maxLen + 1));
            visitedMatrix[r + 1][c] = false;
        }
        if (r - 1 >= 0 && visitedMatrix[r - 1][c] == false && matrix[r - 1][c] > matrix[r][c]) {
            visitedMatrix[r - 1][c] = true;
            maxLen = max(maxLen, findLongest(matrix, r - 1, c, visitedMatrix, maxLen + 1));
            visitedMatrix[r - 1][c] = false;
        }

        if (c + 1 <= matrix[r].size() - 1 && visitedMatrix[r][c + 1] == false && matrix[r][c + 1] > matrix[r][c]) {
            visitedMatrix[r][c + 1] = true;
            maxLen = max(maxLen, findLongest(matrix, r, c + 1, visitedMatrix, maxLen + 1));
            visitedMatrix[r][c + 1] = false;
        }
        if (c - 1 >= 0 && visitedMatrix[r][c - 1] == false && matrix[r][c - 1] > matrix[r][c]) {
            visitedMatrix[r][c - 1] = true;
            maxLen = max(maxLen, findLongest(matrix, r, c - 1, visitedMatrix, maxLen + 1));
            visitedMatrix[r][c - 1] = false;
        }
        return maxLen;
    }

   public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        vector<vector<bool>> visitedMatrix = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size(), false));
        int maxLen = 0;
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[r].size(); ++c) {
                visitedMatrix[r][c] = true;
                maxLen = max(maxLen, findLongest(matrix, r, c, visitedMatrix, 1));
                visitedMatrix[r][c] = false;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    /*
     *     9 9 4
     *     6 6 8
     *     2 1 1
     */
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    assert(4 == sol.longestIncreasingPath(matrix));
    /*
     *    3 4 5
     *    3 2 6
     *    2 2 1
     */
    matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    assert(4 == sol.longestIncreasingPath(matrix));
    /*
     *     1
     */
    matrix = {{1}};
    assert(1 == sol.longestIncreasingPath(matrix));
    return 0;
}

