#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1));
        for (int i = 0; i <= sz1; ++i)
            dp[i][0] = i;
        for (int i = 0; i <= sz2; ++i)
            dp[0][i] = i;
        for (int i = 1; i <= sz1; ++i)
            for (int j = 1; j <= sz2; ++j)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
        return dp[sz1][sz2];
    }
};

int main() {
    Solution sol;
    string s1, s2;
    s1 = "horse", s2 = "ros";
    assert(3 == sol.minDistance(s1, s2));
    s1 = "intention", s2 = "execution";
    assert(5 == sol.minDistance(s1, s2));
    return 0;
}
