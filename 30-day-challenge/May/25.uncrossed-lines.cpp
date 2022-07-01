#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
    Smaller solution: credit: Leetcode::codedayday
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        const int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (A[i - 1] == B[j - 1])});
        return dp[m][n];
    }
    */
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        int H = B.size(), W = A.size();
        if (H == 0 || W == 0)
            return 0;
        vector<vector<int>> dp(H, vector<int>(W, 0));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (i == 0) {
                    if (A[j] == B[i]) {
                        dp[i][j] = 1;
                    } else if (j != 0) {
                        dp[i][j] = dp[i][j - 1];
                    }
                } else if (j == 0) {
                    if (A[j] == B[i]) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    if (A[j] == B[i]) {
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                    } else {
                        dp[i][j] = max({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                    }
                }
            }
        }
        return dp[H - 1][W - 1];
    }
};

int main() {
    Solution sol;
    vector<int> A, B;
    A = {2, 5, 1, 2, 5};
    B = {10, 5, 2, 1, 5, 2};
    assert(3 == sol.maxUncrossedLines(A, B));
    A = {1, 3, 7, 1, 7, 5};
    B = {1, 9, 2, 5, 1};
    assert(2 == sol.maxUncrossedLines(A, B));
    A = {1, 4, 2};
    B = {1, 2, 4};
    assert(2 == sol.maxUncrossedLines(A, B));
    return 0;
}
