#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    void bfs(queue<pair<int, pair<int, int>>> &q, vector<vector<int>> &rooms, vector<vector<bool>> &visited) {
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while (q.empty() == false) {
            int hops = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            for (auto dir : direction) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || y < 0 || x >= rooms.size() || y >= rooms[x].size() || visited[x][y])
                    continue;
                visited[x][y] = true;
                q.push({hops + 1, {x, y}});
                rooms[x][y] = min(rooms[x][y], hops + 1);
            }
        }
    }

   public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int H = rooms.size(), W = rooms[0].size();
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<pair<int, pair<int, int>>> queue;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (rooms[i][j] == 0) {
                    queue.push({0, {i, j}});
                    visited[i][j] = true;
                } else if (rooms[i][j] == -1)
                    visited[i][j] = true;
        bfs(queue, rooms, visited);
    }
};
int main() {
    Solution sol;

    return 0;
}

