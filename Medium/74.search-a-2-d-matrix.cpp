/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * - Integers in each row are sorted from left to right.
 * - The first integer of each row is greater than the last integer of the
 * previous row.
 *
 * Example 1:
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 *
 * Example 2:
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {

    bool binary_search(vector<int> matrix, int beg, int end, const int &target) {
        if (beg > end)
            return false;
        int mid = beg + (end - beg) / 2;
        if (matrix[mid] == target)
            return true;
        else if (matrix[mid] > target)
            return binary_search(matrix, beg, mid - 1, target);
        else
            return binary_search(matrix, mid + 1, end, target);
    }

   public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int R = matrix.size();
        int C = 0;
        if (R > 0)
            C = matrix[0].size();
        else
            return false;
        for (int i = 0; i < R && C > 0; i++) {
            if (matrix[i][C - 1] > target)
                return binary_search(matrix[i], 0, matrix[i].size() - 1, target);
            else if (matrix[i][C - 1] == target)
                return true;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    assert(true == sol.searchMatrix(matrix, 5));
    return 0;
}