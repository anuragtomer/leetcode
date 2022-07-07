#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>> &matrix) {
        int H = matrix.size();
        if (H == 0)
            return;
        int W = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0 || j == 0) {
                        if (i == 0)
                            firstRowZero = true;
                        if (j == 0)
                            firstColZero = true;
                    } else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < H; ++i)
            if (matrix[i][0] == 0)
                for (int j = 1; j < W; ++j)
                    matrix[i][j] = 0;

        for (int j = 1; j < W; ++j)
            if (matrix[0][j] == 0)
                for (int i = 1; i < H; ++i)
                    matrix[i][j] = 0;

        for (int i = 0; i < H && firstColZero; ++i)
            matrix[i][0] = 0;

        for (int j = 0; j < W && firstRowZero; ++j)
            matrix[0][j] = 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    vector<vector<int>> solution = {{0, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    sol.setZeroes(matrix);
    assert(matrix.size() == solution.size());
    for (int i = 0; i < solution.size(); ++i)
        for (int j = 0; j < solution[i].size(); ++j)
            assert(matrix[i][j] == solution[i][j]);

    matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    solution = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    sol.setZeroes(matrix);
    assert(matrix.size() == solution.size());
    for (int i = 0; i < solution.size(); ++i)
        for (int j = 0; j < solution[i].size(); ++j)
            assert(matrix[i][j] == solution[i][j]);

    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    solution = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    sol.setZeroes(matrix);
    assert(matrix.size() == solution.size());
    for (int i = 0; i < solution.size(); ++i)
        for (int j = 0; j < solution[i].size(); ++j)
            assert(matrix[i][j] == solution[i][j]);
    return 0;
}

