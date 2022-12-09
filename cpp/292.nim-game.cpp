/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return (n%4 != 0);    
    }
};
// @lc code=end

int main() {
    int n;
    Solution sol;
    cin >> n;
    cout << boolalpha << sol.canWinNim(n);
    return 0;
}