#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }
    string result;
    if ((numerator > 0 && denominator < 0) ||
        (numerator < 0 && denominator > 0)) {
      result += '-';
    }
    long num = labs(numerator), den = labs(denominator);
    result += to_string(num / den);

    num %= den;
    if (num == 0) {
      return result;
    }

    result += '.';
    unordered_map<long, int> seen_pattern;
    while (num != 0) {
      if (seen_pattern.find(num) != seen_pattern.end()) {
        int pos = seen_pattern[num];
        result.insert(pos, "(");
        result += ')';
        return result;
      } else {
        seen_pattern[num] = result.length();
        num *= 10;
        result += to_string(num / den);
        num %= den;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  int numerator, denominator;
  string expected;
  numerator = 1, denominator = 2, expected = "0.5";
  assert(expected == sol.fractionToDecimal(numerator, denominator));

  numerator = 2, denominator = 1, expected = "2";
  assert(expected == sol.fractionToDecimal(numerator, denominator));

  numerator = 4, denominator = 333, expected = "0.(012)";
  assert(expected == sol.fractionToDecimal(numerator, denominator));

  return 0;
}

