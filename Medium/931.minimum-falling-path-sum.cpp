#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &result) {
        int n = matrix.size();
        for (int j = 0; j < n; ++j)
            result[n - 1][j] = matrix[n - 1][j];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0)
                    result[i][j] = matrix[i][j] + min(result[i + 1][j], result[i + 1][j + 1]);
                else if (j == n - 1)
                    result[i][j] = matrix[i][j] + min(result[i + 1][j - 1], result[i + 1][j]);
                else
                    result[i][j] = matrix[i][j] + min({result[i + 1][j - 1], result[i + 1][j], result[i + 1][j + 1]});
            }
        }
    }

   public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        vector<vector<int>> result(matrix.size(), vector<int>(matrix.size(), INT_MAX));
        if (matrix.size() == 1) {
            int sum = 0;
            for (int i = 0; i < matrix.size(); ++i)
                sum += matrix[i][0];
            return sum;
        }
        if (matrix.size() == 2) {
            int sum = 0;
            for (int i = 0; i < matrix.size(); ++i)
                sum += min(matrix[i][0], matrix[i][1]);
            return sum;
        }
        dfs(matrix, result);
        int minSum = INT_MAX;
        for (int i = 0; i < result.size(); ++i)
            minSum = min(minSum, result[0][i]);
        return minSum;
    }
};

int main() {
    Solution sol;

    return 0;
}

