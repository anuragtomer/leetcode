#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSideJumps(vector<int> &obstacles) {
        int dp[] = {1, 0, 1};
        for (int a : obstacles) {
            if (a > 0)
                dp[a - 1] = 1e6;        // Infinity
            for (int i = 0; i < 3; ++i) // update minimum jumps for each row.
                if (a != i + 1)
                    dp[i] = min(dp[i], min(dp[(i + 1) % 3], dp[(i + 2) % 3]) + 1);
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};

int main() {
    Solution sol;
    vector<int> obstacles = {0, 1, 2, 3, 0};
    assert(2 == sol.minSideJumps(obstacles));
    obstacles = {0, 1, 1, 3, 3, 0};
    assert(0 == sol.minSideJumps(obstacles));
    obstacles = {0, 2, 1, 0, 3, 0};
    assert(2 == sol.minSideJumps(obstacles));
    return 0;
}

