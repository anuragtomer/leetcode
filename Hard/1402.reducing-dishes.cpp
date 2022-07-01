#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Solution 1. Backtracking. O(2^n)
class Solution {
    void knapsack(int satis, int i, int multiplier, vector<int> &s, int &maxSatis) {
        if (i == s.size()) {
            maxSatis = max(maxSatis, satis);
            return;
        }
        knapsack(satis, i+1, multiplier, s, maxSatis);
        knapsack(satis + (s[i]*multiplier), i+1, multiplier+1, s, maxSatis);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int maxSatis = 0;
        knapsack(0, 0, 1, satisfaction, maxSatis);
        knapsack(0, 1, 1, satisfaction, maxSatis);
        return maxSatis;
    }
};
*/
/*
 * DP. O(n^2)
class Solution {
    int knapsack(int satis, int i, int multiplier, vector<int> &s, int &maxSatis, vector<vector<int>> &dp) {
        if (i == s.size()) {
            maxSatis = max(maxSatis, satis);
            return satis;
        }
        if (dp[i][multiplier] == INT_MIN) {
            dp[i][multiplier] = max(knapsack(satis, i+1, multiplier, s, maxSatis, dp), knapsack(satis +
(s[i]*multiplier), i+1, multiplier+1, s, maxSatis, dp));
        }
        return max(maxSatis, dp[i][multiplier]);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int maxSatis = 0;
        vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+1, INT_MIN));
        knapsack(0, 0, 1, satisfaction, maxSatis, dp);
        knapsack(0, 1, 1, satisfaction, maxSatis, dp);
        return maxSatis;
    }
};
*/
// Genius Solution. O(n).
class Solution {
   public:
    int maxSatisfaction(vector<int> &A) {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        for (int i = n - 1; i >= 0 && A[i] > -total;
             --i) { // We run this loop as long as I'm adding some value. 'A[i] - total > 0'.
            total += A[i];
            res += total; // This is basically multiplying previously chosen dishes (5) + (5 + 0) + (5 + 0 + -1) == 5*3
                          // + 0*2 + -1*1
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> s = {-1, -8, 0, 5, -9};
    assert(14 == sol.maxSatisfaction(s));
    return 0;
}
/*
 * Some Notes:
-1 -8 0 5 -7
_sort_
-8 -7 -1 0 5
Call flow:
-> (-8*0, [-7 -1 0 5], 1, 1)
-> (0, [-7 -1 0 5], 1, 0)

(-8*0, [-7 -1 0 5], 1, 1) -> (-8*0 + -7*1, [-1 0 5], 2, 2) -> (-8*0 + -7*1 + -1*2, [0 5], 3, 3) -> (-8*0 + -7*1 + -1*2 +
0*3, [5], 4, 4) -> (-8*0 + -7*1 + -1*2 + 0*3 + 5*4, [], 5, 5) -> 11 |								  |
|										|-> (-8*0 + -7*1 + -1*2 + 0*3, [], 5, 4) -> -9
                          |								  |									   |-> (-8*0 + -7*1 + -1*2, [5], 4, 3) -> (-8*0 + -7*1 +
-1*2 + 5*3, [], 5, 4) -> 6
                          |								  |																		  |-> (-8*0 + -7*1 + -1*2, [], 5, 3)
-> -9
                          |								  |-> (-8*0 + -7*1, [0 5], 3, 2) -> (-8*0 + -7*1 + 0*2, [5], 4, 3) -> (-8*0 +
-7*1 + 0*2 + 5*3, [], 5, 4) -> 8
                          |								  							    |								  |-> (-8*0 + -7*1 + 0*2, [], 5, 3) ->
-7
                          |								  							    |-> (-8*0 + -7*1, [5], 4, 2) -> (-8*0 + -7*1 + 2*5, [],
5, 3) -> 3
                          | 																						|-> (-8*0 + -7*1, [], 5, 2) ->
-7
                          |->(-8*0, [-1 0 5], 2, 1) -> (-8*0 + -1*1, [0 5], 3, 2) -> (-8*0 + -1*1 + 0*2, [5], 4, 3) ->
(-8*0 + -1*1 + 0*2 + 5*3, [], 5, 4) -> 14
                                                   |							 |								   |-> (-8*0 + -1*1 + 0*2, [], 5, 3) ->
-1 |                             |-> (-8*0 + -1*1, [5], 4, 2) -> (-8*0 + -1*1 + 5*2, [], 5, 3)
                                                   |							 							 |-> (-8*0 + -1*1, [], 5,
2)
                                                   |-> (-8*0, [0 5], 3, 1)

int maxSatisfaction(vector<int>& A) {
    sort(A.begin(), A.end());
    int res = 0, total = 0, n = A.size();
    for (int i = n - 1; i >= 0 && A[i] > -total; --i) {
        total += A[i];
        res += total;
    }
    return res;
}


-8 -7 -1 0 5

total = 5
total = 5 + 0
total = 5 + 0 - 1
result = 5 + (5 + 0) + (5 + 0 - 1)
*/
