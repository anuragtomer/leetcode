#include <array>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  static string numberToWords(int n) {
    if (n == 0) {
      return "Zero";
    } else {
      return int_string(n).substr(1);
    }
  }

 private:
  static const array<string, 20> below_20;
  static const array<string, 10> below_100;

  static string int_string(int n) {
    if (n >= 1'000'000'000) {
      return int_string(n / 1'000'000'000) + " Billion" +
             int_string(n - 1'000'000'000 * (n / 1'000'000'000));
    } else if (n >= 1'000'000) {
      return int_string(n / 1'000'000) + " Million" +
             int_string(n - 1'000'000 * (n / 1'000'000));
    } else if (n >= 1'000) {
      return int_string(n / 1'000) + " Thousand" +
             int_string(n - 1'000 * (n / 1'000));
    } else if (n >= 100) {
      return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
    } else if (n >= 20) {
      return " " + below_100[n / 10] + int_string(n - 10 * (n / 10));
    } else if (n >= 1) {
      return " " + below_20[n];
    } else {
      return "";
    }
  }
};

const array<string, 20> Solution::below_20 = {
    "",        "One",     "Two",       "Three",    "Four",
    "Five",    "Six",     "Seven",     "Eight",    "Nine",
    "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const array<string, 10> Solution::below_100 = {
    "" /*Zero*/, "" /*Ten*/, "Twenty",  "Thirty", "Forty",
    "Fifty",     "Sixty",    "Seventy", "Eighty", "Ninety"};

int main() {
  Solution sol;
  assert(sol.numberToWords(1005) == "One Thousand Five");
  assert(sol.numberToWords(14365) ==
         "Fourteen Thousand Three Hundred Sixty Five");
  return 0;
}