/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
#include <iostream>
using namespace std;
/* 
 * All the single digit squares eventually either come to 16 (2,3,4,5,6,8,9) or 1 (1 and 7).
 * 1 - 1 (success)
 * 2 - 4 16 37 58 314 26 40 16
 * 3 - 9 81 65 61(16)
 * 4 - 16 (maps to 16 from 2)
 * 5 - 25 29 85 (maps to 58 from 2)
 * 6 - 36 45 41 17 50 25 (map to 25 from 5)
 * 7 - 49 97 130 10 1 (success)
 * 8 - 64 52(map to 25 from 5)
 * 9 - 81(map to 81 from 3)
*/
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int temp = n;
         do {
            int temp2 = 0;
            temp = n;
            while(temp != 0) {
                temp2 += ((temp % 10) * (temp % 10));
                temp /= 10;
            }
            n = temp2;
        } while(n/10 != 0 && n != 16);
        return (n == 1 || n == 7);
    }
};
// @lc code=end

int main() {
    int n;
    Solution sol;
    cin >> n;
    cout << boolalpha << sol.isHappy(n);
    return 0;
}