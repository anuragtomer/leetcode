#include <iostream>
#include <vector>

using namespace std;

/*
    There are n people and 40 types of hats labeled from 1 to 40.
    Given a list of list of integers hats, where hats[i] is a list of all hats preferred by the i-th person.
    Return the number of ways that the n people wear different hats to each other.
    Since the answer may be too large, return it modulo 10^9 + 7.

    Example 1:
    Input: hats = [[3,4],[4,5],[5]]
    Output: 1
    Explanation: There is only one way to choose hats given the conditions.
    First person choose hat 3, Second person choose hat 4 and last one hat 5.

    Example 2:
    Input: hats = [[3,5,1],[3,5]]
    Output: 4
    Explanation: There are 4 ways to choose hats
    (3,5), (5,3), (1,3) and (1,5)

    Example 3:
    Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
    Output: 24
    Explanation: Each person can choose hats labeled from 1 to 4.
    Number of Permutations of (1,2,3,4) = 24.
*/

class Solution {
   public:
    int numberWays(vector<vector<int>> &hats) {
        int n = hats.size();
        const int MOD = 1e9 + 7;
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int hat = 1; hat <= 40; ++hat) {
            vector<int> dp2(1 << n);
            dp2 = dp;
            vector<int> people;
            for (int who = 0; who < n; ++who) {
                for (int h : hats[who]) {
                    if (h == hat) {
                        // Collect all the people who want the current hat.
                        people.push_back(who);
                    }
                }
            }
            for (int mask = 0; mask < (1 << n); ++mask) {
                for (int who : people) {
                    if (!(mask & (1 << who))) {
                        int &tmp = dp2[mask | (1 << who)];
                        tmp += dp[mask];
                        if (tmp >= MOD) {
                            tmp -= MOD;
                        }
                    }
                }
            }
            dp = dp2;
        }
        return dp[(1 << n) - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> hats;
    hats = {{3, 4}, {4, 5}, {5}};
    assert(1 == sol.numberWays(hats));

    hats = {{3, 5, 1}, {3, 5}};
    assert(4 == sol.numberWays(hats));

    hats = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    assert(24 == sol.numberWays(hats));

    hats = {{1, 2, 3}, {2, 3, 5, 6}, {1, 3, 7, 9}, {1, 8, 9}, {2, 5, 7}};
    assert(111 == sol.numberWays(hats));

    return 0;
}
