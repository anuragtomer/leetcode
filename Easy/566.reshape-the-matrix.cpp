#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        int H = mat.size();
        if (H == 0)
            return mat;
        int W = mat[0].size();
        if (H * W != r * c)
            return mat;
        if (H == r && W == c)
            return mat;
        vector<vector<int>> newMat(r, vector<int>(c, 0));
        for (int i = 0, k = 0, l = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                newMat[k][l] = mat[i][j];
                ++l;
                if (l == c) {
                    l = 0;
                    ++k;
                }
            }
        }
        return newMat;
    }
};
int main() {
    Solution sol;

    return 0;
}

