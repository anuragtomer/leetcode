#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) {
        int h = matrix.size() - 1;
        for (int i = 0; i <= h / 2; ++i)
            swap(matrix[i], matrix[h - i]);
        for (int i = 0; i <= h; ++i)
            for (int j = i; j <= h; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

void printMatrix(vector<vector<int>> &matrix) {
    for (auto row : matrix) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
}
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix);
    printMatrix(matrix);
    return 0;
}

