#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int H = dungeon.size();
        if (H == 0)
            return 1;
        int W = dungeon[0].size();
        vector<vector<int>> dp(H + 1, vector<int>(W + 1, INT_MAX));
        dp[H][W - 1] = 1;
        dp[H - 1][W] = 1;
        for (int i = H - 1; i >= 0; --i) {
            for (int j = W - 1; j >= 0; --j) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    assert(7 == sol.calculateMinimumHP(dungeon));
    return 0;
}
