/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <iostream>
#include <vector>
#include "lib.hpp"
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
  vector<int> digits = vectors::create_vector(n);
  vector<int> expected = {1, 2, 4}, output = sol.plusOne(digits);
  assert(vectors::match_unsorted_vecs(expected, output));
  return 0;
}