#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /* Way 1
    int numSquares(int n) {
        vector<int> dp{0};
        while (dp.size() <= n) {
            int m = dp.size(), count = INT_MAX;
            for (int i = 1; i * i <= m; ++i)
                count = min(count, dp[m - i * i] + 1);
            dp.push_back(count);
        }
        return dp[n];
    }
    */
    /* Way 2: Loops interchanged, runs faster.
    int numSquares(int n) {
        vector<int> dp {0};
        int m = dp.size();
        dp.resize(max(m, n+1), INT_MAX);
        for (int i=1, i2; (i2 = i*i)<=n; ++i)
            for (int j=max(m, i2); j<=n; ++j)
                if (dp[j] > dp[j-i2] + 1)
                    dp[j] = dp[j-i2] + 1;
        return dp[n];
    }
    */
    /* Way 3: Super cool solution:*/
    bool isSquare(int n) {
        int sqroot = sqrt(n);
        return (n == (sqroot * sqroot));
    }
    int numSquares(int n) {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        if (isSquare(n))
            return 1;
        for (int i = 1; i * i <= n; i++)
            if (isSquare(n - i * i))
                return 2;
        return 3;
    }
};

int main() {
    Solution sol;
    assert(3 == sol.numSquares(12));
    assert(2 == sol.numSquares(13));
    return 0;
}
