/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    /* int addDigits(int num) {
        return 1 + (num - 1) % 9;
    } */
    
    int addDigits(int num) {
        while(num/10 != 0) {
            int temp = 0;
            int temp2 = num;
            while(temp2 != 0) {
                temp += temp2%10;
                temp2 /= 10;
            }
            num = temp;
        }
        return num;
    }
   
};
// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.addDigits(n);
    return 0;
}