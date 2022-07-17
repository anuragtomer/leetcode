class Solution {
 public:
  /*
  int kInversePairs(int N, int K) {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;
    if (dp[N][K] != 0) 
      return dp[N][K]; 
    for (int n = 1; n <= N; ++n) 
      for (int k = 0; k <= K; ++k) { 
        dp[n][k] = dp[n - 1][k];
        if (k > 0)
          dp[n][k] = (dp[n][k] + dp[n][k - 1]) % 1000000007;
        if (k >= n) 
          dp[n][k] = (1000000007 + dp[n][k] - dp[n - 1][k - n]) % 1000000007; 
      } 
    return dp[N][K]; 
  }
  */
  int kInversePairs(int N, int K) {
    int dp[2][1001] = {1};
    for (int n = 1; n <= N; ++n)
      for (int k = 0; k <= K; ++k) {
        int curr = n % 2, last = (n - 1) % 2;
        dp[curr][k] = dp[last][k];
        if (k > 0)
          dp[curr][k] = (dp[curr][k] + dp[curr][k - 1]) % 1000000007;
        if (k >= n)
          dp[curr][k] =
            (1000000007 + dp[curr][k] - dp[last][k - n]) % 1000000007;
      }
    return dp[N % 2][K];
  }
};
int main() { return 0; }
