#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countSquares(vector<vector<int>> &matrix) {
        int H = matrix.size();
        if (H == 0)
            return 0;
        int W = matrix[0].size();
        int answer = 0;
        for (int i = 0; i < H; ++i)
            if (matrix[i][W - 1] == 1)
                answer += matrix[i][W - 1];

        for (int i = 0; i < W; ++i)
            if (matrix[H - 1][i] == 1)
                answer += matrix[H - 1][i];

        answer -= matrix[H - 1][W - 1];

        for (int i = H - 2; i >= 0; --i) {
            for (int j = W - 2; j >= 0; --j) {
                matrix[i][j] =
                    matrix[i][j] == 1 ? 1 + min({matrix[i + 1][j], matrix[i + 1][j + 1], matrix[i][j + 1]}) : 0;
                answer += matrix[i][j];
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    assert(15 == sol.countSquares(matrix));
    matrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    assert(7 == sol.countSquares(matrix));
    return 0;
}
