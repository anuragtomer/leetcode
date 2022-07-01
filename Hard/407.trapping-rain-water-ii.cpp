#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int trapRainWater(vector<vector<int>> &nums) {
        struct heightData {
            int i;
            int j;
            int height;
        };
        auto comp = [](heightData &a, heightData &b) { return a.height > b.height; };
        priority_queue<heightData, vector<heightData>, decltype(comp)> pq(comp);
        int H = nums.size();
        if (H == 0)
            return 0;
        int W = nums[0].size();
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        for (int i = 0; i < H; ++i) {
            visited[i][0] = true;
            pq.push({i, 0, nums[i][0]});
            visited[i][W - 1] = true;
            pq.push({i, W - 1, nums[i][W - 1]});
        }
        for (int j = 0; j < W; ++j) {
            visited[0][j] = true;
            pq.push({0, j, nums[0][j]});
            visited[H - 1][j] = true;
            pq.push({H - 1, j, nums[H - 1][j]});
        }
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int water = 0;
        while (!pq.empty()) {
            auto [i, j, height] = pq.top();
            pq.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + direction[k][0], y = j + direction[k][1];
                if (x < 0 || y < 0 || x >= H || y >= W || visited[x][y])
                    continue;
                visited[x][y] = true;
                pq.push({x, y, max(height, nums[x][y])});
                if (nums[x][y] < height) {
                    water += height - nums[x][y];
                }
            }
        }
        return water;
    }
};

int main() {
    Solution sol;

    return 0;
}

