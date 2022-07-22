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
 * [1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 *
 * Example 2:
 *
 * Input:
 * matrix = [
 * [1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {

  bool binary_search(vector<int>::iterator start, vector<int>::iterator end,
                     int target) {
    while (start != end) {
      auto mid = start + (end - start) / 2;
      if (*mid == target)
        return true;
      else if (*mid < target)
        start = next(mid);
      else
        end = mid;
    }
    return false;
  }

 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    for (int i = 0, j = matrix[0].size() - 1; i < matrix.size(); ++i) {
      if (target == matrix[i][j])
        return true;
      else if (target < matrix[i][j])
        return binary_search(matrix[i].begin(), matrix[i].end(), target);
    }
    return false;
  }
};*/
class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int lb = 0, ub = matrix.size();
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (matrix[mid][0] == target)
        return true;
      else if (matrix[mid][0] < target)
        lb = mid + 1;
      else
        ub = mid;
    }
    if (lb == 0)
      return false;
    int i = lb - 1;
    lb = 0, ub = matrix[i].size();
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (matrix[i][mid] == target)
        return true;
      else if (matrix[i][mid] < target)
        lb = mid + 1;
      else
        ub = mid;
    }
    return false;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> matrix = {
    {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  assert(true == sol.searchMatrix(matrix, 5));
  return 0;
}
