#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minCost(vector<vector<int>> &costs) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        int n = costs.size();
        int i = 1;
        for (; i <= n; ++i) {
            dp[i % 2][0] = costs[(i - 1)][0] + min(dp[(i + 1) % 2][1], dp[(i + 1) % 2][2]);
            dp[i % 2][1] = costs[(i - 1)][1] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][2]);
            dp[i % 2][2] = costs[(i - 1)][2] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]);
        }
        return min(dp[(i - 1) % 2][0], min(dp[(i - 1) % 2][1], dp[(i - 1) % 2][2]));
    }
};

int main() {
    Solution sol;
    vector<vector<int>> costs = {{14, 2, 11}, {11, 14, 5}, {14, 3, 10}};
    assert(10 == sol.minCost(costs));
    return 0;
}

