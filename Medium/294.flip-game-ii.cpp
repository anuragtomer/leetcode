#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    unordered_map<string, bool> dp;
    bool canWin(string &s) {
        if (dp.count(s))
            return dp[s];
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                bool win = canWin(s);
                s[i] = '-';
                s[i + 1] = '-';
                if (!win)
                    dp[s] = !win;
            }
        }
        return dp[s];
    }
};

int main() {
    Solution sol;

    return 0;
}

