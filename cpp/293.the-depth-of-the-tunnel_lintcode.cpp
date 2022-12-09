#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param matrix: the matrix in problem
     * @return: the depth of the tunnel.
     */
    int FindDepth(vector<vector<int>> &matrix) {
        int H = matrix.size(), W = matrix[0].size();
        int depth = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            matrix[i][j] = 0;
            depth = max(depth, i);
            if (depth == H - 1)
                return depth;
            for (auto dir : direction) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || y < 0 || x >= H || y >= W || matrix[x][y] == 0)
                    continue;
                q.push({x, y});
                matrix[x][y] = 0;
            }
        }
        return depth;
    }
};

int main() {
    Solution sol;

    return 0;
}

