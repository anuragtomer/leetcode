/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <iostream>
#include <vector>
#include "../include/utility.h"
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0;
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            *it += 1;
            if (*it > 9) {
                carry = 1;
                *it %= 10;
            } else {
                carry = 0;
                break;
            }
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string n = "1,2,3";
    vector<int> digits = createVector<int>(n);
    vector<int> expected = {1, 2, 4}, output = sol.plusOne(digits);
    assert(true == testResp(output, expected));
    return 0;
}