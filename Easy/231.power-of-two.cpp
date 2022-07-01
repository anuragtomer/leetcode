/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        while(n > 1) {
            if (n & 1 == 1)
                return false;
            n = n >> 1;
        }
        if (n & 1 == 1)
            return true;
        return false;
    }
};
// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << boolalpha << sol.isPowerOfTwo(n);
    return 0;
}