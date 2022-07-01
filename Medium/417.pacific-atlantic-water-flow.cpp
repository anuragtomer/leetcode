#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
 * One DFS based slow solution.
 */
/*
class Solution {
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>> &canReach, int m, int n, vector<vector<int>> &nums) {
        if (canReach[i][j] == 0x11)
            return canReach[i][j];
        canReach[i][j] |= 0x100;
        for (auto dir : direction) {
            if (i + dir[0] < 0 || i + dir[0] >= m || j + dir[1] < 0 || j + dir[1] >= n)
                continue;
            if (canReach[i + dir[0]][j + dir[1]] & (0x100))
                continue;
            if (nums[i][j] >= nums[i + dir[0]][j + dir[1]])
                canReach[i][j] |= dfs(i + dir[0], j + dir[1], canReach, m, n, nums);
        }
        canReach[i][j] &= 0x11;
        return canReach[i][j];
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> canReach(m, vector<int>(n, 0));
        auto printBin = [](int num) -> string {
            string str;
            int i = 0;
            while (i != 4) {
                str += to_string(num % 2);
                num /= 2;
                ++i;
            }
            return string(str.rbegin(), str.rend());
        };
        auto print = [](string f(int), vector<vector<int>> &vec) {
            cout << "++++++++++++++" << endl;
            for (auto row : vec) {
                for (auto val : row)
                    cout << f(val) << " ";
                cout << endl;
            }
        };
        auto normal = [](int num) -> string { return to_string(num); };
        print(normal, heights);
        for (int i = 0; i < m; ++i) {
            canReach[i][0] = 0x1;
            canReach[i][n - 1] = 0x10;
        }
        for (int i = 0; i < n; ++i) {
            canReach[0][i] = 0x1;
            canReach[m - 1][i] = 0x10;
        }
        canReach[0][n - 1] = canReach[m - 1][0] = 0x11;
        print(printBin, canReach);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                canReach[i][j] |= dfs(i, j, canReach, m, n, heights);
        }
        print(printBin, canReach);
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (canReach[i][j] == 0x11)
                    result.push_back({i, j});
        return result;
    }
};
*/
// Another bfs/dfs based solution using 2 matrices, one for atlantic, another for pacific.
class Solution {
    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visited, vector<vector<int>> &nums, int m, int n) {
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (auto dir : direction) {
                auto x = i + dir[0], y = j + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
                    continue;
                if (nums[i][j] <= nums[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        vector<vector<int>> result;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atlantic(m, vector<bool>(n, false)), pacific(m, vector<bool>(n, false));
        queue<pair<int, int>> atlanticQueue, pacificQueue;
        for (int i = 0; i < m; ++i) {
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, n - 1});
        }
        for (int i = 0; i < n; ++i) {
            pacific[0][i] = true;
            atlantic[m - 1][i] = true;
            pacificQueue.push({0, i});
            atlanticQueue.push({m - 1, i});
        }
        bfs(pacificQueue, pacific, heights, m, n);
        bfs(atlanticQueue, atlantic, heights, m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> result = sol.pacificAtlantic(heights);
    for (auto res : result)
        cout << res[0] << " " << res[1] << endl;
    return 0;
}

