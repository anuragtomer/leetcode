#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int r = 0;
        int c = matrix[0].size() - 1;
        while(r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target)
                return true;
            else if (target < matrix[r][c])
                c--;
            else
                r++;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {{1,   4,  7, 11, 15},
                                  {2,   5,  8, 12, 19},
                                  {3,   6,  9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};

    assert(true == sol.searchMatrix(matrix, 5));
    assert(false == sol.searchMatrix(matrix, 20));
    cout << "All test cases passed.\n";
    return 0;
}