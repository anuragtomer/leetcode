/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    /* 
    Solution 1:
    int climbStairs(int n) {
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        if (n > 1)
            return second;
        else return first;
    } */
    int climbStairs(int n) {
        return (1/sqrt(5)) * (pow(((1 + sqrt(5))/2), (n+1)) - pow(((1 - sqrt(5))/2), (n+1)));
    }
};

// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.climbStairs(n);
    return 0;
}