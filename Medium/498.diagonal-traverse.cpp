#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int H = mat.size(), W = mat[0].size();
        vector<int> result(H * W);
        int i = 0, j = 0, k = 0, d = 0;
        int dir[2][2] = {{-1, 1}, {1, -1}};
        while (k < H * W) {
            result[k] = mat[i][j];
            ++k;
            i += dir[d][0];
            j += dir[d][1];
            if (i >= H) {
                i = H - 1;
                j += 2;
                d = 1 - d;
            }
            if (j >= W) {
                j = W - 1;
                i += 2;
                d = 1 - d;
            }
            if (i < 0) {
                i = 0;
                d = 1 - d;
            }
            if (j < 0) {
                j = 0;
                d = 1 - d;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

